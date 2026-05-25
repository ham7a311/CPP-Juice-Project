#include "JuiceShop.h"
Menu& JuiceShop::getMenu(){ //Getting the menu using Encapsulation
   return menu;
 }
void JuiceShop::addEmployee(Employee emp){
  employees.push_back(emp); //Adding a new employee to the employees vector
}


void JuiceShop::createOrder(Order ord){
   orders.push_back(ord); //Adding a new order to the orders vector

   cout << "Your Order ID is: " << ord.getOrderID() << endl;
}


void JuiceShop::displayOrders(){
   if(orders.empty()){
      cout<<"There are no orders in the system yet."<<endl; //Checking first if the orders vectors empty, if not then it will start using the loop
      return;
         }
   for(int i=0; i<orders.size(); i++){ // A loop to go through all of the orders using the orders vector
     orders[i].showOrderDetails(); // shoing each order detaild using the "showOrderDetails()" function from order class
   }
}


void JuiceShop::checkOrder(int id){
   for(int i=0; i<orders.size(); i++){
      if(id==orders[i].getOrderID()){
       orders[i].showOrderDetails();
         return;
      }
   }
   cout<<"Order with ID: "<<id<<" not found!"<<endl;
}


// Checkout an order using polymorphism with different payment methods.
void JuiceShop::checkoutOrder(int id) {
    for (int i = 0; i < orders.size(); i++) {
        if (id == orders[i].getOrderID()) {

            double total = orders[i].calculateTotal();

            //Handles the case when no employee are available
            try {
                Employee emp = getRandomEmployee();
                cout << "Order handled by Employee:" << endl;
                emp.displayPersonInfo();
            }
            catch (const runtime_error& e) {
                cout << "Employee Error: " << e.what() << endl;
                return;
            }

            cout << "Total bill: " << total << " OMR" << endl;

            Payment::showPaymentMethods();

            cout << "Choose payment method: ";
            int choice;
            cin >> choice;

            Payment* payment = nullptr;

            try {
                if (choice == 1) {
                    double cash;
                    cout << "Enter cash amount: ";
                    cin >> cash;

                    payment = new CashPayment(total, cash);
                }
                else if (choice == 2) {
                    string cardNumber;
                   cout << "Enter Visa card number: ";
                   cin >> cardNumber;
               
                   if (cardNumber.length() != 16) {
                       cout << "Visa card number must be 16 digits.\n";
                       return;
                   }
               
                   payment = new VisaPayment(total, cardNumber);
                }
                else if (choice == 3) {
                    string cardNumber;
                    cout << "Enter American Express card number: ";
                    cin >> cardNumber;
               
                    if (cardNumber.length() != 15) {
                       cout << "American Express card number must be 15 digits.\n";
                       return;
                    }
               
                    payment = new AmericanExpressPayment(total, cardNumber);
                }
                else {
                    throw invalid_argument("Invalid payment method choice.");
                }

                payment->processPayment();
                payment->displayPaymentInfo();

                orders[i].completeOrder();

                cout << "Successful checkout, order completed." << endl;

                delete payment;
            }
            catch (const invalid_argument& e) {
                cout << "Payment Error: " << e.what() << endl;

                if (payment != nullptr) {
                    delete payment;
                }
            }

            return;
        }
    }

    cout << "Order not found." << endl;
}



Employee JuiceShop::getRandomEmployee(){
   if ( employees.empty()) {
        throw runtime_error("No employees available.");
    }
   
   int index = rand() % employees.size();
   return employees[index];
}
