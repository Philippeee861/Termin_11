#include <iostream>
// Hier Ihre Gatter-Header inkludieren (z.B. #include "AndGate.h")

int main() {
    // 1. Globaler Test-Status
    bool testPassed = true;

    std::cout << "--- STARTE AUTOMATISIERTE WAHRHEITSTABELLEN-TESTS ---" << std::endl;

    // 2. Beispiel-Testblock für ein AND-Gatter (Stellvertretend für alle Gatter)
    {
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!)
        auto andGate = std::make_unique<AndGate>(); 
        
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis
        int testCases[4][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 0, 0},
            {1, 1, 1}
        };

        for (int i = 0; i < 4; ++i) {
            andGate->setInput(0, testCases[i][0]);
            andGate->setInput(1, testCases[i][1]);
            andGate->evaluate();
            
            if (andGate->getOutput() != testCases[i][2]) {
                std::cerr << "❌ TEST FAILED: AND bei Inputs A=" << testCases[i][0] 
                          << " B=" << testCases[i][1] 
                          << " -> Erhalten: " << andGate->getOutput() 
                          << " (Erwartet: " << testCases[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // [!] HIER WEITERE TESTBLÖCKE FÜR OR, NOT, XOR, NAND ERGÄNZEN (Insgesamt min. 18 Fälle)

    // 3. Finale Auswertung für die CI-Pipeline
    if (!testPassed) {
        std::cerr << "--- 🔴 PIPELINE-ABSTURZ: TESTS FEHLGESCHLAGEN ---" << std::endl;
        return 1; // Signalisiert GitHub Actions: FEHLER!
    }

    std::cout << "--- 🟢 ALLER TESTS BESTANDEN (18/18) ---" << std::endl;
    return 0; // Signalisiert GitHub Actions: ERFOLG!
}


// Sabotage im Code:
output = inputA | inputB; // FALSCH!
