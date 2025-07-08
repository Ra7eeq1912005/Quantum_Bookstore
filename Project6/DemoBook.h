#pragma once
#include "Book.h"
class DemoBook :
    public Book
{
public:
    DemoBook(string Title, long yearOfPublish, double Price,long Quantity) :
        Book( Title, yearOfPublish, Price,Quantity) {

    }
     bool forSale() const override {
        return false;
    }

       double buy(long bookQuantity, const string& email = "", const string& address = "") override {
        
             throw runtime_error("Invalid Sale");
         
     }
};

