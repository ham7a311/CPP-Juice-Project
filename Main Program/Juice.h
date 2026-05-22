#ifndef JUICE_H
#define JUICE_H

#include <iostream>
using namespace std;

class Juice {
    private:
        string juiceName;           // "Mango", "Strawberry", "Banana", "Pineapple", "Mint", "Ice"
        double basePrice;    // basePrice -> the starting price for every juice(this is decided in menu)

    public:
        //Constructor
        Juice(string juiceName, double basePrice);


        //getters
        string getJuiceName() const;// const because it only return the value of juiceName not changing it
        double getBasePrice() const;


        // A function to set the basePrice based on the size of the juice.
        double calculatePrice(char size) const; // const because it does not change any data member, it only reads the basePrice and returns the price after the modifications.


        // A function to display the Info. of the Juice.
        void displayJuiceInfo() const;    // const because it only displays the Info.

};

#endif
