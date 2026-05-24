#include <iostream>
#include "JuiceShop.h"
#include "Customer.h"
#include "Employee.h"
#include "Order.h"
using namespace std;

int main() {

    JuiceShop shop;

    // define menu items with their prices (OMR)
    shop.getMenu().addJuice(Juice("Mango", 1.5));
    shop.getMenu().addJuice(Juice("Strawberry", 1.2));
    shop.getMenu().addJuice(Juice("Banana", 1.0));
    shop.getMenu().addJuice(Juice("Pineapple", 1.4));
    shop.getMenu().addJuice(Juice("Mint", 1.3));
    shop.getMenu().addJuice(Juice("Ice", 1.1));

    while (true) {
        
        cout << "1. View Menu" << endl;
        cout << "2. Create Custom Juice" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            
            shop.getMenu().showMenu();

        } else if(choice == 2) {
            
            cout << "not ready yet";    // we should implement JuiceBuilder funcionality here, print a fixed text for now because its not ready yet, but this should be changed
            
        }  else if(choice == 3) {
            
            string name, phoneNumber;

            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your phone number: ";
            cin >> phoneNumber;

            Customer customer(name, phoneNumber);

            Order newOrder(customer);

            int count;
            cout << "Enter how many juices you want: ";
            cin >> count;

            for (int i = 0; i < count; i++) {

                // print this for every count
                // if count = 2 this whole loop will be printed 2 times, and so on (might need a limit here)
                
                string juiceName;
                char size;

                cout << "Juice name: ";
                cin >> juiceName;

                cout << "Size (S/M/L) or (s/m/l): ";
                cin >> size;

                newOrder.addJuiceToOrder(Juice(juiceName, 1.0), size);    // this needs better implementation, basePrice is fixed for now but it should'nt be
                
            }

            shop.createOrder(newOrder);

        } else if (choice == 4) {
            cout << "Exiting the system";
            break; // break/exit the loop
        } else {
            cout << "Invalid choice, enter a a number from 1 to 4 only" << endl;
        }
    }

    return 0;

}
