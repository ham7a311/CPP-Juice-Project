#include "Juice.h"


//Constructor
Juice::Juice(string juiceName, double basePrice, char size) {
            this->basePrice = basePrice;
            this->juiceName = juiceName;
            this->size = size;
}


// Juice name getter (Needed in Menu.h)
string Juice::getJuiceName() const {     // const because it only return the value of juiceName not changing it
            return juiceName;
}

// A function to set the basePrice based on the size of the juice.
double Juice::calculatePrice() const  {            // const because it does not change any data member, it only reads the basePrice and returns the price after the modifications.
      if (size == 'S' || size == 's') {
          return basePrice;                               //if the cup size is SMALL, price will be same, return basePrice
      } else if (size == 'M' || size == 'm') {  
          return basePrice + (basePrice * 0.5);           // if cup size is MEDIUM, price will be 50% more, return basePrice + (basePrice * 0.5)
      } else if (size == 'L' || size == 'l') {        
          return basePrice * 2;                               // if cup size is LARGE, price will be double ,return basePrice * 2
      } else {
                /*  
                 if size is not valid return -1
                 then handle the logic in displayJuiceInfo()
                 how to handle logic in displayJuiceInfo():
                                                - Call  calculatePrice(), and assign it to a variable
                                                - if that variable is -1    ===>    cout an error
                                                - else   ===>   continue the program
                */
                
                return -1;                                 
    }
}


// A function to display the Info. of the Juice.
void Juice::displayJuiceInfo() const{          // const because it only displays the Info.

      double finalPrice = calculatePrice();           // call caculatePrice() to get the price variable and assign it to finalPrice
            
      if (finalPrice == -1) cout << "Something went wrong (Invalid size)" << endl;
      else {
            cout << "--------------- Juice Informations --------------" << endl;
            cout << "Juice name: " << juiceName << endl;        // display juiceName
            cout << "Size: " << size << endl;            // display juice size
            cout << "Price: " << finalPrice << endl;            // display finalPrice (price after adjusting and checking size)
            }    
  
      cout << "-------------------------------------------------" << endl;
            
}

