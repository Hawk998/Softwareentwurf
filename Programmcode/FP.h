#ifndef FP_H
#define FP_H

// Definition des Typs FP (Stapelstruktur)
typedef struct {
    int *items;
    int top;
    int capacity;
} FP;

// Prototypen der spezifizierten Prozeduren
void initStack(FP *stack, int capacity);
int isStackEmpty(FP *stack);
int stackLength(FP *stack);
void push(FP *stack, int item);
int pop(FP *stack);
int peek(FP *stack);
void printStack(FP *stack);
void freeStack(FP *stack);
int replace(FP *stack, int i, int x);

#endif