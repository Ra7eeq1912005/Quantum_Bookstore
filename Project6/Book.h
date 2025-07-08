#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
protected:
    string title;
    long yearOfPublish;
    double price;
    long quantity;

public:
    Book( string title, long yearOfPublish, double price, long quantity)
        : title(title), yearOfPublish(yearOfPublish), price(price), quantity(quantity)  {
    }

    virtual ~Book() = default; 

    string getTitle() const {
        return title;
    }

    long getYearOfPublished() const {
        return yearOfPublish;
    }

    double getPrice() const {
        return price;
    }

    long getQuantity() const {
        return quantity;
    }

    void setQuantity(long q) {
        quantity = q;
    }

    virtual bool forShipped() const {
        return false;
    }

    virtual bool forSale() const {
        return true;
    }

    virtual bool canBeSendViaEmail() const {
        return false;
    }

    virtual double buy(long bookQuantity, const string& email = "", const string& address = "") {
        if (bookQuantity > quantity) {
            throw runtime_error("Quantum book store: Invalid book quantity requested.");
        }

        quantity -= bookQuantity;

        return price * bookQuantity;
    }

    
};
