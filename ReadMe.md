# README - Stack-based Calculator in C

## Projektbeschreibung

Dieses Projekt implementiert einen einfachen, stackbasierten Rechner in der Programmiersprache C. Der Rechner verwendet die **Postfix-Notation** (auch Reverse Polish Notation, RPN), um arithmetische Ausdrücke zu verarbeiten. In der Postfix-Notation stehen die Operanden vor den Operatoren, was es ermöglicht, die Ausdrücke ohne Klammern auszuwerten. Zusätzlich gibt es die Möglichkeit, mit dem Operator `$` zwei Elemente des Stacks zu tauschen.

Die Stapeloperationen (`Push`, `Pop`, `Peek`, etc.) werden mit Hilfe einer benutzerdefinierten **Stack-Datenstruktur** implementiert. Eine kleine Testdatei (`stacktest.c`) demonstriert zudem die Funktionalität des Stapels.

## Funktionsweise

### Dateien

Das Projekt besteht aus folgenden Dateien:

1. **rechner.c**: Hauptprogramm für den Postfix-Rechner. Es verarbeitet die Eingabe des Benutzers und führt arithmetische Operationen durch.
2. **FP.h**: Header-Datei mit Definitionen und Prototypen für die Stack-Datenstruktur und die zugehörigen Operationen.
3. **FP.c**: Implementierung der Stack-Datenstruktur und ihrer Operationen.
4. **stacktest.c**: Testprogramm zur Überprüfung der Stapelfunktionen (Push, Pop, Replace, etc.).

### Postfix-Rechner

Das Programm erwartet vom Benutzer einen Ausdruck in der Postfix-Notation, z.B.:

```bash
3 4 * 2 +
Das Ergebnis ist: 14

## Stapelfunktionen

Die Datei `stacktest.c` dient zur Überprüfung der Stapelfunktionen. Sie führt verschiedene Stapeloperationen wie `Push`, `Pop`, `Replace` und `Peek` durch und gibt den aktuellen Zustand des Stapels aus.

### Übersicht der Stapeloperationen:

- **Push**: Fügt ein Element oben auf den Stapel.
- **Pop**: Entfernt das oberste Element vom Stapel und gibt es zurück.
- **Peek**: Gibt das oberste Element zurück, ohne es zu entfernen.
- **Replace**: Ersetzt ein bestimmtes Element auf dem Stapel durch einen neuen Wert.
- **PrintStack**: Gibt den gesamten Stapel aus.

## Speicherverwaltung

Die `freeStack()`-Funktion stellt sicher, dass der für den Stapel reservierte Speicher nach Beendigung des Programms freigegeben wird.

## Anforderungen

- C Compiler (z.B. `gcc`)
- Terminal oder IDE zum Kompilieren und Ausführen des Programms

## Zusammenfassung

Dieses Projekt implementiert einen einfachen Postfix-Rechner mit einer Stack-Datenstruktur in C. Es unterstützt grundlegende arithmetische Operationen und bietet eine spezielle Funktion zum Tauschen der Stapelwerte. Das `stacktest.c` Programm erlaubt es, die korrekte Funktion der Stapeloperationen zu testen.
