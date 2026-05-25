#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "JuiceShop.h"
#include "Customer.h"
#include "Employee.h"
#include "Order.h"
#include "JuiceBuilder.h"
using namespace std;

int main() {

    srand(time(0));

    JuiceShop shop;

    // define menu items with their prices (OMR)
    shop.getMenu().addJuice(Juice("Mango", 1.5));
    shop.getMenu().addJuice(Juice("Strawberry", 1.2));
    shop.getMenu().addJuice(Juice("Banana", 1.0));
    shop.getMenu().addJuice(Juice("Pineapple", 1.4));
    shop.getMenu().addJuice(Juice("Mint", 1.3));
    shop.getMenu().addJuice(Juice("Ice", 1.1));

    // add employees
    shop.addEmployee(Employee("E1", "Ahmed", "92938390", "Cashier"));
    shop.addEmployee(Employee("E2", "Mohammed", "92922920", "Cashier"));
    shop.addEmployee(Employee("E3", "Ali", "9282020", "Cashier"));

    while (true) {
        
        cout << "1. View Menu" << endl;
        cout << "2. Create Custom Juice" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. View Orders" << endl;
        cout << "5. Checkout Order" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            
            shop.getMenu().showMenu();

        } else if(choice == 2) {
            
            JuiceBuilder juiceBuilder;

            string customJuiceName;
            cout << "Enter the name of your custom juice: ";
            cin >> customJuiceName;

            
            while(true) {
                juiceBuilder.showAvailableIngredients();
                
                string ingredient;
                cout << "Enter ingredients (enter '-' to finish your custom juice): ";
                cin >> ingredient;

                if(ingredient == "-") {
                    break; // break the loop when user enter "-", we used "-" instead of '-' because its a string not char
                }

                juiceBuilder.addIngredient(ingredient);


                juiceBuilder.displayCustomMix();
 
          }

            
            // must add try and catch handle error if custom juice without ingredients
            Juice custom = juiceBuilder.createCustomJuice(customJuiceName);

            shop.getMenu().addJuice(custom);
            
        }  else if(choice == 3) {
            
            string name, phoneNumber;

            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter phone number (press - to skip): ";
            cin >> phoneNumber;

            Customer customer(name); 

            if (phoneNumber != "-") {
                customer = Customer(name, phoneNumber);  // if user does not skip by clicking - , add the phone number user typed
            }

            Order newOrder(customer);    // add customer order

            int count;
            cout << "Enter how many juices you want: ";
            cin >> count;

            if (count <= 0) {
                cout << "Invalid number of juices" << endl;
                continue;
            }

            for (int i = 0; i < count; i++) {

                // print this for every count
                // if count = 2 this whole loop will be printed 2 times, and so on (might need a limit here of how many number of juices user can order)
                
                int juiceNumberChoice;
                char size;

                cout << "Juice number: ";
                cin >> juiceNumberChoice;

                cout << "Size (S/M/L) or (s/m/l): ";
                cin >> size;

                // users enters the number next to the juice, and we find the juice name by looping through the vector and finding vector[juicNumberChoice-1]
                // we should handle invalid number by the user as well
                Juice juice = shop.getMenu().getJuiceByIndex(juiceNumberChoice);    // use the function that returns a juice object from Menu.cpp, juice now will include both name of juice and it price
                
                double handleInvalidSize = juice.calculatePrice(size);    

                if(handleInvalidSize == -1) {
                    // handle when size = -1 (this must print to user that he typed an inavlid size
                   // ask user for size again
                }

                newOrder.addJuiceToOrder(juice, size);
                
                
            }

            shop.createOrder(newOrder);

        } else if (choice == 4) {
            shop.displayOrders();
        } else if (choice == 5) {
            
            int id;
            cout << "Enter your order id to complete checkout: ";
            cin >> id;

            shop.checkoutOrder(id);
            
        } else if (choice == 6) {
            cout << "Exiting the system";
            break; // break/exit the loop
        } else {
            cout << "Invalid choice, enter a a number from 1 to 6 only" << endl;
        }
    }

    return 0;

}
