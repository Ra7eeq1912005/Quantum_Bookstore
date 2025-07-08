#pragma once
#include <iostream>
#include <string>
#include <map>
#include <ctime>       
#include "Book.h"
#include "PaperBook.h"
#include "EBook.h"
#include "DemoBook.h"

using namespace std;

class Inventory {
public:
    map<string, Book*> inventoryList;

    void addBook(const string& ISBN, Book* book) {
        inventoryList[ISBN] = book;
        cout << " book with " << ISBN << " is added to inventory." << "\n";
    }

    void removeOutDated(long max_age) {
        int currentYear = getCurrentYear();
        auto it = inventoryList.begin();

        while (it != inventoryList.end()) {
            Book* book = it->second;
            long bookYear = book->getYearOfPublished();

            if ((currentYear - bookYear) > max_age) {
                cout << " outdated book with " << it->first << " is removed \n";
                delete book;   
                it = inventoryList.erase(it);   
            }
            else {
                ++it;
            }
        }
    }

    ~Inventory() {
        for (auto& pair : inventoryList) {
            delete pair.second;
        }
        inventoryList.clear();
    }

    double buyBook(  string  ISBN, long Quantity, const string& email = "", const string& address = "") {
        auto it = inventoryList.find(ISBN);
        if (it == inventoryList.end()) {
            throw runtime_error(" The book is not found");
        }

        Book* book = it->second;
        return book->buy(Quantity, email, address);
    }


private:
    int getCurrentYear() const {
        time_t t = time(0);
        struct tm timeinfo;
        localtime_s(&timeinfo, &t);   
        return timeinfo.tm_year + 1900;
    }

};
