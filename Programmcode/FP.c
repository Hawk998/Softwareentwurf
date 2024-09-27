#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

// Initialisiere den Stapel (Stack)
// Diese Funktion reserviert Speicher für den Stack und setzt die Startwerte
void initStack(FP *stack, int capacity) {
    // Speicher allokieren für das Array, das die Stack-Elemente speichert
    stack->items = (int *)malloc(sizeof(int) * capacity);
    // Setzt den `top`-Index auf -1, um anzuzeigen, dass der Stack leer ist
    stack->top = -1;
    // Speichert die maximale Kapazität des Stacks
    stack->capacity = capacity;
}

// Prüfe, ob der Stapel leer ist
// Gibt 1 zurück, wenn der Stack leer ist, ansonsten 0
int isStackEmpty(FP *stack) {
    return stack->top == -1;
}

// Gib die aktuelle Länge des Stapels zurück
// Da der `top`-Index bei -1 beginnt, ist die Länge `top + 1`
int stackLength(FP *stack) {
    return stack->top + 1;
}

// Füge ein neues Element zum Stapel hinzu
// Die Funktion prüft zuerst, ob noch Platz auf dem Stack ist, bevor ein neues Element hinzugefügt wird
void push(FP *stack, int item) {
    // Prüfen, ob der Stack voll ist
    if (stack->top == stack->capacity - 1) {
        printf("Stapel ist voll.\n");
        return;
    }
    // Erhöht den `top`-Index und fügt das Element an dieser Stelle hinzu
    stack->items[++stack->top] = item;
}

// Entferne das oberste Element vom Stapel und gib es zurück
int pop(FP *stack) {
    // Überprüfen, ob der Stack leer ist
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return -1;  // Rückgabe bei leerem Stack (Fehlerwert)
    }
    // Gibt das oberste Element zurück und verringert den `top`-Index
    return stack->items[stack->top--];
}

// Gib das oberste Element des Stapels zurück, ohne es zu entfernen
int peek(FP *stack) {
    // Überprüfen, ob der Stack leer ist
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return -1;  // Rückgabe bei leerem Stack (Fehlerwert)
    }
    // Gibt das oberste Element zurück, ohne den `top`-Index zu verändern
    return stack->items[stack->top];
}

// Drucke den Inhalt des Stapels aus
void printStack(FP *stack) {
    // Überprüfen, ob der Stack leer ist
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return;
    }
    // Ausgabe des gesamten Stacks, von unten nach oben
    printf("Stapel: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Gib den Speicher, der für den Stapel allokiert wurde, wieder frei
void freeStack(FP *stack) {
    free(stack->items);
}

// Ersetze ein Element an einer bestimmten Position im Stapel
int replace(FP *stack, int i, int x) {
    // Überprüfen, ob der Index innerhalb der Stack-Grenzen liegt
    if (i <= stackLength(stack) - 1) {
        // Ersetzen des Elements an der Stelle `i` durch den Wert `x`
        stack->items[i] = x;
        return 1;  // Erfolgreich ersetzt
    } else {
        // Fehlermeldung, wenn der Index außerhalb des gültigen Bereichs liegt
        printf("Index i %d liegt außerhalb des Stacks.\n", i);
        return 0;  // Fehler
    }
}
