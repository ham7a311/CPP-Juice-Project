#include "JuiceShop.h"
Menu& JuiceShop::getMenu(){ //Getting the menu using Encapsulation
   return menu;
 }
void JuiceShop::addEmployee(Employee emp){
  employees.push_back(emp); //Adding a new employee to the employees vector
}
