#pragma once
#include "Inventory.h"

class Test {
public:
    static void run() {
        Inventory inventory;

        try {
             
            Book* paperBook = new PaperBook("The C++ Guide", 2016, 200.0, 50, 30);
            Book* ebook = new EBook("AI Fundamentals", 2021, 120.0, "PDF", 100);
            Book* demoBook = new DemoBook("Quantum physics", 2012, 0.0, 1);

            inventory.addBook("ISBN-PB001", paperBook);
            inventory.addBook("ISBN-EB001", ebook);
            inventory.addBook("ISBN-DB001", demoBook);

             
            cout << "\n--- Buying a PaperBook ---\n";
            double amount1 = inventory.buyBook("ISBN-PB001", 2, "", "123 Cairo Street");
            cout << " Total paid Amount= " << amount1 << " \n";

             
            cout << "\n--- Buying an EBook ---\n";
            double amount2 = inventory.buyBook("ISBN-EB001", 1, "user@example.com", "");
            cout << " Total paid Amount = " << amount2 << "  \n";

            
            cout << "\n--- Attempting to Buy a DemoBook (should fail) ---\n";
            inventory.buyBook("ISBN-DB001", 1);
        }
        catch (const exception& e) {
            cout << "Exception - " << e.what() << "\n";
        }

         
        cout << "\n--- Removing Outdated Books ---\n";
        inventory.removeOutDated(5);

        cout << "\n test ends sucssefully.\n";
    }
};
