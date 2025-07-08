#pragma once
#include "Book.h"
#include "ShippingService.h"
class PaperBook :
    public Book
{
private:
    long stock;
public:
    PaperBook(  string Title, long yearOfPublish, double Price,long Quantity,long stock)
        :Book(  Title, yearOfPublish, Price,Quantity),stock(stock) {

    }
    bool forShipped() const override  {
        return true;
    }
      double buy(long bookQuantity, const string& email = "", const string& address = "") override{
        if (bookQuantity > quantity) {
            throw runtime_error("Quantum book store: Invalid book quantity requested.");
        }
        if (bookQuantity > stock) {
            cout << "NOTE THAT: the required quantity may be take more time to recieve  \n ";
        }

        quantity -= bookQuantity;
        stock -= bookQuantity;

        send_to_Shipping( address);
        return price * bookQuantity;
    }
      void send_to_Shipping(const string& address) {
          cout << "Quantum book store: Sending Paper Book to" << " " << address << " ShippingService\n";

      }
       
  
};

