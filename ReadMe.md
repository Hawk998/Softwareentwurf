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
