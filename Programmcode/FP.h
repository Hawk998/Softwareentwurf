#ifndef FP_H
#define FP_H

// Definition der Stack-Struktur FP
typedef struct {
    int *items;      // Zeiger auf ein Array von Stack-Elementen (int)
    int top;         // Index des obersten Elements auf dem Stack (gibt an, wie hoch der Stapel ist)
    int capacity;    // Maximale Kapazität des Stacks (wie viele Elemente gespeichert werden können)
} FP;

// Funktionsprototypen zur Verwaltung und Nutzung des Stacks

// Initialisiert den Stack mit einer bestimmten Kapazität (reserviert Speicher für die Elemente)
void initStack(FP *stack, int capacity);

// Überprüft, ob der Stack leer ist (gibt 1 zurück, wenn der Stack leer ist, sonst 0)
int isStackEmpty(FP *stack);

// Gibt die aktuelle Länge des Stacks zurück (wie viele Elemente sich derzeit auf dem Stack befinden)
int stackLength(FP *stack);

// Legt ein neues Element (item) auf den Stack (oben drauf)
void push(FP *stack, int item);

// Entfernt das oberste Element vom Stack und gibt es zurück
int pop(FP *stack);

// Gibt das oberste Element des Stacks zurück, ohne es zu entfernen
int peek(FP *stack);

// Gibt alle Elemente des Stacks aus (zum Debugging)
void printStack(FP *stack);

// Gibt den vom Stack reservierten Speicher wieder frei (zum Aufräumen)
void freeStack(FP *stack);

// Ersetzt das Element an der Position `i` im Stack durch das Element `x`
// Dies ist eine erweiterte Funktion, die direkten Zugriff auf ein bestimmtes Stack-Element erlaubt
int replace(FP *stack, int i, int x);

#endif
