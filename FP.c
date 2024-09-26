#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

// Initialisiere den Stapel
void initStack(FP *stack, int capacity) {
    stack->items = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

// Prüfe, ob der Stapel leer ist
int isStackEmpty(FP *stack) {
    return stack->top == -1;
}

// Gib die Länge des Stapels zurück
int stackLength(FP *stack) {
    return stack->top + 1;
}

// Füge ein Element zum Stapel hinzu
void push(FP *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stapel ist voll.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Nimm ein Element vom Stapel
int pop(FP *stack) {
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return -1; // oder eine andere Fehlerrückgabe
    }
    return stack->items[stack->top--];
}

// Gib das oberste Element des Stapels zurück
int peek(FP *stack) {
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return -1; // oder eine andere Fehlerrückgabe
    }
    return stack->items[stack->top];
}

// Drucke den Stapel
void printStack(FP *stack) {
    if (isStackEmpty(stack)) {
        printf("Stapel ist leer.\n");
        return;
    }
    printf("Stapel: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Gib den Speicher des Stapels frei
void freeStack(FP *stack) {
    free(stack->items);
}

// Ersetzt das angegebene Stapelelement
int replace(FP *stack, int i, int x) {
    if (i <= stackLength(stack) - 1)
    {
        stack->items[i] = x;
        return 1;
    }
    else
    {
        printf("Index i %d liegt außerhalb des Stacks.\n", i);
        return 0;
    }
}