# C++ Digital Simulator 🔌

[![C++ Automated Tests](https://github.com/dantschi/digisim/actions/workflows/ci.yml/badge.svg)](https://github.com/dantschi/digisim/actions/workflows/ci.yml)

Ein **C++-basierter Simulator für digitale Logikgatter** mit automatisierter CI/CD-Pipeline – ideal zum Verständnis von Schaltlogik, Speichermanagement und DevOps-Konzepten.

## 📋 Überblick

Dieses Projekt implementiert einen vollständigen Logik-Simulator mit verschiedenen digitalen Gattern:

- **AND-Gate** – Logisches UND
- **OR-Gate** – Logisches ODER  
- **NOT-Gate** – Logische Negation
- **XOR-Gate** – Exklusives ODER
- **NAND-Gate** – Negiertes UND

## 🏗️ Projektstruktur

```
├── Component.h/cpp        # Abstrakte Basisklasse für alle Gatter
├── LogicEngine.h/cpp      # Kern-Engine zur Verwaltung von Schaltungen
├── AndGate.h/cpp          # AND-Gatter-Implementierung
├── OrGate.h/cpp           # OR-Gatter-Implementierung
├── NotGate.h/cpp          # NOT-Gatter-Implementierung
├── XorGate.h/cpp          # XOR-Gatter-Implementierung
├── NandGate.h/cpp         # NAND-Gatter-Implementierung
├── main.cpp               # Automatisierte Test-Suite mit Exit-Codes
├── README.md              # Diese Datei
└── .github/
    └── workflows/
        └── ci.yml         # GitHub Actions CI/CD Pipeline
```

## 🎯 Kernkonzepte

### Polymorphismus
Alle Gatter erben von der abstrakten Basisklasse `Component` und implementieren die virtuelle Methode `update()`. Die `LogicEngine` verwaltet die Komponenten polymorphisch über `std::unique_ptr<Component>`.

### Speichermanagement
Das Projekt demonstriert modernes C++ Speichermanagement mit:
- **Smart Pointers** (`std::unique_ptr`) statt rohe Zeiger
- Automatische Speicherfreigabe ohne Memory Leaks
- RAII-Prinzip (Resource Acquisition Is Initialization)

### CI/CD & Automatisierung
GitHub Actions triggert automatisch bei jedem `git push`:
- ✅ Code-Kompilierung
- ✅ Wahrheitstabellen-Tests (19 automatisierte Tests)
- ✅ Exit-Code Validierung
- ✅ Statische Code-Analyse (cppcheck)

## 🚀 Kompilierung & Ausführung

### Voraussetzungen
- C++17 oder höher
- Ein C++-Compiler (GCC, Clang, MSVC)

### Lokal kompilieren
```bash
g++ *.cpp -o simulator
./simulator
```

### Erfolg (Exit-Code 0)
```
Test Summary:
Bestanden: 19 / 19
========================================

[SUCCESS] Alle Tests bestanden! ✓
```

### Fehler (Exit-Code 1)
```
[FEHLER] Mindestens ein Test fehlgeschlagen!
Die CI-Pipeline wird dies als FEHLER markieren.
```

## 🤖 Automatisierte Tests

Die `main.cpp` führt umfassende Wahrheitstabellen-Tests durch:

| Gatter | Tests | Status |
|--------|-------|--------|
| AND    | 4     | ✓      |
| OR     | 4     | ✓      |
| NOT    | 2     | ✓      |
| XOR    | 4     | ✓      |
| NAND   | 4     | ✓      |
| Integration | 1 | ✓      |
| **Gesamt** | **19** | **✓** |

## 📊 GitHub Actions Pipeline

Jeden `git push` ausgelöst:

```yaml
on:
  push:
    branches: [ "main" ]

jobs:
  build-and-test:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v4
      - name: Kompiliere
        run: g++ *.cpp -o simulator
      - name: Teste
        run: ./simulator
      - name: Static Analysis
        run: cppcheck --enable=all --error-exitcode=1 *.cpp
```

Der Status wird oben als Badge angezeigt! ✨

## 💾 Verwendungsbeispiel

```cpp
LogicEngine engine;
engine.setCircuitName("Beispiel-Schaltung");

// Komponenten hinzufügen
engine.addComponent(std::make_unique<AndGate>("AND-1"));
engine.addComponent(std::make_unique<OrGate>("OR-1"));

// Schaltung simulieren
engine.doTick();
```

## 📚 Weitere Informationen

Dieses Projekt ist Teil des Moduls **Informatik 2 – Labor 7** an der DHBW Stuttgart und behandelt:
- Objektorientiertes Programmieren (OOP)
- Speichermanagement mit Smart Pointers
- DevOps & Continuous Integration
- Automatisierte Testausführung

## 📝 Lizenz

Hochschulprojekt – Verwendung zu Bildungszwecken.

---

**Viel Erfolg beim Programmieren!** 🎓
