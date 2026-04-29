#ifndef juice_h
#define juice_h

#include <iostream>
using namespace std;

class Juice {
    private:
        string juiceName;
        double basePrice, price;
        char size;

    public:
        Juice(string juiceName, double basePrice, char size) {
            this->basePrice = basePrice;
            this->juiceName = juiceName;
            this->size = size;
        }

        double calculatePrice() {
            if(size == 'S' || size == 's') {
                price = basePrice;
            }else if (size == 'M' || size == 'm') {
                price = basePrice + (basePrice * 0.5);
            }else {
                price = basePrice + basePrice;
            }

            return price;
        }

};

#endif
