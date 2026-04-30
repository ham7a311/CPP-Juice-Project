#ifndef juice_h
#define juice_h

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
                return price;
            }else if (size == 'M' || size == 'm') {
                price = basePrice + (basePrice * 0.5);
                return price;
            }else if(size == 'L' || size == 'l') {
                price = basePrice + basePrice;
                return price;
            } else {
                return -1;
            }
        }

};

#endif
