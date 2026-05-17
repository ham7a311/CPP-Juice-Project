#include "JuiceShop.h"
Menu& JuiceShop::getMenu(){ //Getting the menu using Encapsulation
   return menu;
 }
void JuiceShop::addEmployee(Employee emp){
  employees.push_back(emp); //Adding a new employee to the employees vector
}
void JuiceShop::CreateOrder(Order ord){
   orders.push_back(ord); //Adding a new order to the orders vector
}
void JuiceShop::DisplayOrders(){
   
