#include "Employee.h"


//Constructor
Employee::Employee(string ID, string n, string phone, string r) : Person(n, phone){
    employeeID = ID;
    role = r;
}


//Setter
void Employee::setEmployeeID(string ID){
    employeeID = ID;
}

void Employee::setRole(string r){
    role = r;
}


//Getter
string Employee::getEmployeeID() const{
    return employeeID;
}

string Employee::getRole() const{
    return role;
}



//Order Processing
void Employee::processOrder() const{
    cout << "***************************************************" << endl;
    cout << name << " with the ID: " << employeeID << " is processing your order :)" << endl;
}



// Add Juice to Menu
void Employee::addJuiceToMenu(string juiceName) const{
    cout << "***************************************************" << endl;
    cout << juiceName << " added to the menu." << endl;
}


//Display
void Employee::displayEmployeeInfo() const{
    cout << "***************************************************" << endl;
    cout << "Employee Info" << endl;
    cout << "--------------" << endl;
    cout << "EmployeeID: " << employeeID << endl;
    displayPersonInfo();
    cout << "Role: " << role << endl;
}