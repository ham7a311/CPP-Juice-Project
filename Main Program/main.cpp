#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "JuiceShop.h"
#include "Customer.h"
#include "Employee.h"
#include "Order.h"
#include "JuiceBuilder.h"
#include "OrderReport.h"

using namespace std;

int main() {

    srand(time(0));    // Seed the getRandomEmployee() function

    JuiceShop shop;

    // Define menu items with their prices (OMR)
    shop.getMenu().addJuice(Juice("Mango", 1.5));
    shop.getMenu().addJuice(Juice("Strawberry", 1.2));
    shop.getMenu().addJuice(Juice("Banana", 1.0));
    shop.getMenu().addJuice(Juice("Pineapple", 1.4));
    shop.getMenu().addJuice(Juice("Mint", 1.3));
    shop.getMenu().addJuice(Juice("Ice", 1.1));

    // Add employees
    shop.addEmployee(Employee("E1", "Ahmed", "92938390", "Cashier"));
    shop.addEmployee(Employee("E2", "Mohammed", "92922920", "Cashier"));
    shop.addEmployee(Employee("E3", "Ali", "9282020", "Cashier"));

    while (true) {

        cout << "\n========== Juice Shop System ==========" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Create Custom Juice" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. View Orders" << endl;
        cout << "5. Checkout Order" << endl;
        cout << "6. Exit" << endl;
        cout << "=======================================" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            shop.getMenu().showMenu();

        } 
        else if (choice == 2) {

            string name, phoneNumber;

            cout << "Enter your name: ";
            cin >> name;

            cout << "Enter phone number (press - to skip): ";
            cin >> phoneNumber;

            Customer customer(name);

            if (phoneNumber != "-") {
                customer = Customer(name, phoneNumber);
            }

            Order newOrder(customer);

            JuiceBuilder juiceBuilder;

            string customJuiceName;
            cout << "Enter the name of your custom juice: ";
            cin >> customJuiceName;

            while (true) {
                juiceBuilder.showAvailableIngredients();

                int ingredient;
                cout << "Enter ingredient number (enter -1 to finish your custom juice): ";
                cin >> ingredient;

                if (ingredient == -1) {
                    break;
                }

                if (ingredient >= 1 && ingredient <= juiceBuilder.getSize()) {
                    string ingredientName = juiceBuilder.getIngredientUsingIndex(ingredient);
                    juiceBuilder.addIngredient(ingredientName);
                } 
                else {
                    cout << "Invalid ingredient number." << endl;
                }

                juiceBuilder.displayCustomMix();
            }

            // Handles error if custom juice is created without ingredients
            try {
                Juice custom = juiceBuilder.createCustomJuice(customJuiceName);

                char size;
                cout << "Size of Custom Juice (S/M/L) or (s/m/l): ";
                cin >> size;

                double handleInvalidSize = custom.calculatePrice(size);

                while (handleInvalidSize == -1) {
                    cout << "Invalid size, enter Size (S/M/L) or (s/m/l): ";
                    cin >> size;

                    handleInvalidSize = custom.calculatePrice(size);
                }

                newOrder.addJuiceToOrder(custom, size);

                shop.createOrder(newOrder);

                cout << "Custom Juice Order placed successfully." << endl;
                newOrder.showOrderDetails();

                // Friend class usage
                OrderReport report;
                report.printOrderReport(newOrder);
            } 
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cout << "Custom Juice Order failed." << endl;
            }

        } 
        else if (choice == 3) {

            string name, phoneNumber;

            cout << "Enter your name: ";
            cin >> name;

            cout << "Enter phone number (press - to skip): ";
            cin >> phoneNumber;

            Customer customer(name);

            if (phoneNumber != "-") {
                customer = Customer(name, phoneNumber);
            }

            Order newOrder(customer);

            cout << "-------- Select juices from the menu below ---------" << endl;
            shop.getMenu().showMenu();

            int count;
            cout << "Enter how many juices you want: ";
            cin >> count;

            if (count <= 0) {
                cout << "Invalid number of juices." << endl;
                continue;
            }

            for (int i = 0; i < count; i++) {

                int juiceNumberChoice;
                char size;

                cout << "Juice number: ";
                cin >> juiceNumberChoice;

                cout << "Size (S/M/L) or (s/m/l): ";
                cin >> size;

                try {
                    Juice juice = shop.getMenu().getJuiceUsingIndex(juiceNumberChoice);

                    double handleInvalidSize = juice.calculatePrice(size);

                    while (handleInvalidSize == -1) {
                        cout << "Invalid size, enter Size (S/M/L) or (s/m/l): ";
                        cin >> size;

                        handleInvalidSize = juice.calculatePrice(size);
                    }

                    newOrder.addJuiceToOrder(juice, size);
                } 
                catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    i--;       // Ask again for this juice
                    continue;
                }
            }

            shop.createOrder(newOrder);

            cout << "Order placed successfully." << endl;
            newOrder.showOrderDetails();

            // Friend class usage
            OrderReport report;
            report.printOrderReport(newOrder);

        } 
        else if (choice == 4) {

            shop.displayOrders();

        } 
        else if (choice == 5) {

            int id;
            cout << "Enter your order id to complete checkout: ";
            cin >> id;

            shop.checkoutOrder(id);

        } 
        else if (choice == 6) {

            cout << "Exiting the system." << endl;
            break;

        } 
        else {

            cout << "Invalid choice, enter a number from 1 to 6 only." << endl;

        }
    }

    return 0;
}