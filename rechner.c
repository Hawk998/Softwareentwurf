#include <stdio.h>
#include "FP.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int istOperator(char *t) {
    return (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 || strcmp(t, "*") == 0 || strcmp(t, "/") == 0) || strcmp(t, "$") == 0;
}

void auswert(char *operator, FP *stack) {
    if (strcmp(operator, "$") == 0) {
        printStack(stack);
        int operand1 = peek(stack);
        int operand2 = stack->items[0];
        replace(stack, 0, operand1);
        replace(stack, stackLength(stack) - 1, operand2);
        printStack(stack);
    }
    else
    {

    int operand2 = pop(stack);  // Zuerst den zweiten Operanden vom Stapel holen
    int operand1 = pop(stack);  // Dann den ersten Operanden vom Stapel holen
    int result;

    if (strcmp(operator, "+") == 0) {
        result = operand1 + operand2;
    } else if (strcmp(operator, "-") == 0) {
        result = operand1 - operand2;
    } else if (strcmp(operator, "*") == 0) {
        result = operand1 * operand2;
    } else if (strcmp(operator, "/") == 0) {
        if (operand2 == 0) {
            printf("Division durch Null ist nicht erlaubt.\n");
            exit(EXIT_FAILURE);
        }
        result = operand1 / operand2;
    }
    
     else {
        printf("Ungültiger Operator: %s\n", operator);
        exit(EXIT_FAILURE);
    }
    push(stack, result);  // Ergebnis zurück auf den Stapel legen
    }

    
}

int main() {


    

    FP stack;
    initStack(&stack, 10); // Stapel mit Kapazität 10

    char t[100];  // Buffer zum Einlesen der Zeichenkette
    printf("Geben Sie einen Ausdruck in Postfix-Notation ein (z.B. '3 4 * 2 +'): ");
    
    if (fgets(t, sizeof(t), stdin) != NULL) {
    t[strcspn(t, "\n")] = 0;  // Zeilenumbruch entfernen
    char *token = strtok(t, " ");
        while (token != NULL) {
            if (istOperator(token)) {
                auswert(token, &stack);
				if (strcmp(operator, "$") == 0){
					return 0;
				}
            } 
			else {
                int num = atoi(token);  // Umwandlung der Zeichenkette in eine Zahl
                push(&stack, num);          // Zahl auf den Stapel legen
            }
            token = strtok(NULL, " ");
        }
    }

    // Endergebnis vom Stapel holen und ausgeben
    if (isStackEmpty(&stack) != 1) {
        int result = pop(&stack);
        if (isStackEmpty(&stack) == 1) {
            printf("Das Ergebnis ist: %d\n", result);
        } else {
            printStack(&stack);
            printf("Fehler: Zu viele Operanden auf dem Stapel.\n");
        }
    } else {
        printf("Fehler: Kein Ergebnis auf dem Stapel.\n");
    }

    return 0;
        
    }



