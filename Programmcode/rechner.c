#include <stdio.h>
#include "FP.h"  // Einbindung der Header-Datei für den Stack
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Diese Funktion überprüft, ob das übergebene Token (t) ein Operator ist
int istOperator(char *t) {
    // Vergleich des Tokens mit den Operatoren (+, -, *, / und $)
    return (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 || strcmp(t, "*") == 0 || strcmp(t, "/") == 0) || strcmp(t, "$") == 0;
}

// Diese Funktion wertet den Operator aus und führt die entsprechende Operation auf dem Stack durch
void auswert(char *operator, FP *stack) {
    // Spezielle Behandlung für den '$'-Operator, der anscheinend eine Stack-Modifikation durchführt
    if (strcmp(operator, "$") == 0) {
        printStack(stack);  // Druckt den aktuellen Stackinhalt
        int operand1 = peek(stack);  // Holen des obersten Elements vom Stack (ohne es zu entfernen)
        int operand2 = stack->items[0];  // Zugriff auf das erste Element des Stacks
        replace(stack, 0, operand1);  // Tauscht das erste Element des Stacks mit dem obersten aus
        replace(stack, stackLength(stack) - 1, operand2);  // Tauscht das letzte Element mit dem ersten
        printStack(stack);  // Druckt den modifizierten Stackinhalt
    }
    else {
        // Standardbehandlung für arithmetische Operatoren
        int operand2 = pop(stack);  // Holen des zweiten Operanden (oberstes Element)
        int operand1 = pop(stack);  // Holen des ersten Operanden
        int result;

        // Berechnung des Ergebnisses je nach Operator
        if (strcmp(operator, "+") == 0) {
            result = operand1 + operand2;
        } else if (strcmp(operator, "-") == 0) {
            result = operand1 - operand2;
        } else if (strcmp(operator, "*") == 0) {
            result = operand1 * operand2;
        } else if (strcmp(operator, "/") == 0) {
            // Behandlung der Division durch Null
            if (operand2 == 0) {
                printf("Division durch Null ist nicht erlaubt.\n");
                exit(EXIT_FAILURE);  // Beendet das Programm bei Division durch Null
            }
            result = operand1 / operand2;
        } else {
            // Ungültiger Operator
            printf("Ungültiger Operator: %s\n", operator);
            exit(EXIT_FAILURE);  // Beendet das Programm bei ungültigem Operator
        }

        push(stack, result);  // Legt das Ergebnis zurück auf den Stack
    }
}

// Hauptprogramm
int main() {
    FP stack;
    initStack(&stack, 10);  // Initialisiert den Stack mit einer Kapazität von 10

    char t[100];  // Puffer zum Einlesen der Zeichenkette (Postfix-Ausdruck)
    printf("Geben Sie einen Ausdruck in Postfix-Notation ein (z.B. '3 4 * 2 +'): ");
    
    // Liest den Postfix-Ausdruck von der Standardeingabe ein
    if (fgets(t, sizeof(t), stdin) != NULL) {
        t[strcspn(t, "\n")] = 0;  // Entfernt den Zeilenumbruch aus der Eingabe

        char *token = strtok(t, " ");  // Zerlegt den Ausdruck in Token (getrennt durch Leerzeichen)
        while (token != NULL) {
            // Überprüft, ob das Token ein Operator ist
            if (istOperator(token)) {
                auswert(token, &stack);  // Wertet den Operator aus
				if (strcmp(token, "$") == 0){
					return 0;  // Beendet das Programm bei '$'-Operator
				}
            } else {
                // Konvertiert das Token in eine Zahl und legt sie auf den Stack
                int num = atoi(token);  
                push(&stack, num);
            }
            token = strtok(NULL, " ");  // Nächstes Token
        }
    }

    // Überprüft, ob das Ergebnis korrekt auf dem Stack liegt
    if (isStackEmpty(&stack) != 1) {
        int result = pop(&stack);  // Holt das Ergebnis vom Stack
        if (isStackEmpty(&stack) == 1) {
            printf("Das Ergebnis ist: %d\n", result);  // Gibt das Ergebnis aus
        } else {
            printStack(&stack);
            printf("Fehler: Zu viele Operanden auf dem Stapel.\n");  // Zu viele Zahlen auf dem Stack
        }
    } else {
        printf("Fehler: Kein Ergebnis auf dem Stapel.\n");  // Kein Ergebnis auf dem Stack
    }

    return 0;  // Programmende
}
