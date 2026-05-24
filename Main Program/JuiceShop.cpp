#include "JuiceShop.h"
Menu& JuiceShop::getMenu(){ //Getting the menu using Encapsulation
   return menu;
 }
void JuiceShop::addEmployee(Employee emp){
  employees.push_back(emp); //Adding a new employee to the employees vector
}
void JuiceShop::createOrder(Order ord){
   orders.push_back(ord); //Adding a new order to the orders vector
}
void JuiceShop::displayOrders()const{
   if(orders.empty()){
      cout<<"There are no orders in the system yet."<<endl; //Checking first if the orders vectors empty, if not then it will start using the loop
      return;
         }
   for(int i=0; i<orders.size(); i++){ // A loop to go through all of the orders using the orders vector
     orders[i].showOrderDetails(); // shoing each order detaild using the "showOrderDetails()" function from order class
   }
}
void JuiceShop::checkOrder(int id)const{
   for(int i=0; i<orders.size(); i++){
      if(id==orders[i].getOrderID()){
       orders[i].showOrderDetails();
         return;
      }
   }
   cout<<"Order with ID"<<id<<" not found!"<<endl;
}
void JuiceShop::checkoutOrder(int id){
   for(int i=0; i<orders.size(); i++){
      if(id==orders[i].getOrderID()){
         double total=orders[i].calculateTotal();
         cout<<"Total bill:"<< total<<endl;
         payment::showpaymentMethods()
       Cout << "choose payment method"<<endl;
       int choice
       cin>>choice;
          Payment*payment=nullptr
         if choice==1{
           paymen=Cash;
               }
         else if choice==2{
           paymenyKethod=Visa;
         }
      
       orders[i].completeOrder();
       cout<<"Successful checkout, Order completed."<<endl;
         if (payment!=nullptr){
            delete payment;
         }
       return;
      }
   }
   cout<<"Order not found"<<endl;
}
