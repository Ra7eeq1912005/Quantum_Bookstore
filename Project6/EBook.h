#pragma once
#include "Book.h"
class EBook :
    public Book
{
private:
    string fileType;

public:
    EBook(string Title, long yearOfPublish, double Price, string fileType,long Quantity) :
        Book( Title, yearOfPublish, Price,Quantity), fileType(fileType) {

    }
     bool canBeSendViaEmail()const override{
        return true;
    }

     double buy(long bookQuantity, const string& email = "", const string& address = "") override {
         if (bookQuantity > quantity) {
             throw runtime_error("Quantum book store: Invalid book quantity requested.");
         }
          

         quantity -= bookQuantity;
         //stock -= bookQuantity;

         send_to_email(email);
         return price * bookQuantity;
     }
     void send_to_email(const string& email) {
         cout << "Quantum book store: Sending eBook to" << " " << email << " MailService\n";

     }
};

