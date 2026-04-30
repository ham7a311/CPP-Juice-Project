#ifndef juice_h
#define juice_h

#include <iostream>
using namespace std;

class Juice {
    private:
        string juiceName;           // "Mango", "Strawberry", "Banana", "Pineapple", "Mint", "Ice"
        double basePrice, price;    // basePrice -> the starting price for every juice, price -> final price (after choosing size)
        char size;      // size of juice

    public:
        Juice(string juiceName, double basePrice, char size) {
            this->basePrice = basePrice;
            this->juiceName = juiceName;
            this->size = size;
        }

        double calculatePrice() {
            if(size == 'S' || size == 's') {
                price = basePrice;                          // if cup size is SMALL, price = basePrice
                return price;                               // return price
            }else if (size == 'M' || size == 'm') {
                price = basePrice + (basePrice * 0.5);      // if cup size is MEDIUM, price will be 50% more
                return price;                               // return price
            }else if(size == 'L' || size == 'l') {
                price = basePrice + basePrice;              // if cup size is LARGE, price will be double
                return price;                               // return price
            } else {
                /*  
                 if size is not valid return -1
                 then handle the logic in main()
                 how to handle logic in main:
                                                - Call  calculatePrice(), and assign it to a variable
                                                - if that variable is -1    ===>    cout an error
                                                - else   ===>   continue the program
                */
                
                return -1;                                 
            }
        }

};

#endif
