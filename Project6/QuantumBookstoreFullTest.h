#pragma once
#include "Inventory.h"

class QuantumBookstoreFullTest {
public:
    static void run() {
        Inventory inventory;

        try {
            // Add books
            Book* paperBook = new PaperBook("The C++ Guide", 2016, 200.0, 50, 30);
            Book* ebook = new EBook("AI Fundamentals", 2021, 120.0, "PDF", 100);
            Book* demoBook = new DemoBook("Quantum Concepts", 2012, 0.0, 1);

            inventory.addBook("ISBN-PB001", paperBook);
            inventory.addBook("ISBN-EB001", ebook);
            inventory.addBook("ISBN-DB001", demoBook);

            // Buy a paper book
            cout << "\n--- Buying a PaperBook ---\n";
            double amount1 = inventory.buyBook("ISBN-PB001", 2, "", "123 Cairo Street");
            cout << "Quantum book store: Total paid = " << amount1 << " EGP\n";

            // Buy an ebook
            cout << "\n--- Buying an EBook ---\n";
            double amount2 = inventory.buyBook("ISBN-EB001", 1, "user@example.com", "");
            cout << "Quantum book store: Total paid = " << amount2 << " EGP\n";

            // Try to buy a demo book
            cout << "\n--- Attempting to Buy a DemoBook (should fail) ---\n";
            inventory.buyBook("ISBN-DB001", 1);
        }
        catch (const exception& e) {
            cout << "Quantum book store: Exception caught - " << e.what() << "\n";
        }

        // Remove outdated books (older than 5 years)
        cout << "\n--- Removing Outdated Books ---\n";
        inventory.removeOutDated(5);

        cout << "\nQuantum book store: Test completed.\n";
    }
};
