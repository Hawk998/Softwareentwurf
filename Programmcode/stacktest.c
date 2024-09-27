#include <stdio.h>
#include "FP.h"

int main() {
    FP stack;
    initStack(&stack, 10); // Stapel mit Kapazität 10

    // (1) Einen leeren Stapel erzeugen
    // Bereits durch initStack geschehen

    // (2) den Stapel ausgeben
    printStack(&stack);

    // (3) ausgeben, ob der Stapel leer ist
    printf("Stapel ist leer: %s\n", isStackEmpty(&stack) ? "ja" : "nein");

    // (4) Länge des Stapels ausgeben
    printf("Länge des Stapels: %d\n", stackLength(&stack));

    // (5) drei Elemente hinzufügen
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // (6) den Stapel ausgeben
    printStack(&stack);

    // (7) ein Element wegnehmen
    printf("Element entfernt: %d\n", pop(&stack));

    // (8) den Stapel ausgeben
    printStack(&stack);

    //Neuer Test Replace
    printf("Stapel Replacen:");
    //replace(&stack, 2, 5);
    //replace(&stack, 3, 7);
    replace(&stack, 0, 9);
    //replace(&stack, 1, 8);
    printStack(&stack);

    // (9) ausgeben, ob der Stapel leer ist
    printf("Stapel ist leer: %s\n", isStackEmpty(&stack) ? "ja" : "nein");

    // (10) Länge des Stapels ausgeben
    printf("Länge des Stapels: %d\n", stackLength(&stack));

    // (11) oberstes Element des Stapels ausgeben
    printf("Oberstes Element des Stapels: %d\n", peek(&stack));

    // Speicher freigeben
    freeStack(&stack);

    return 0;
}
