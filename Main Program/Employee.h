#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

// -------------------------- Base Class --------------------------
class Employee {
private:
    string employeeID,name,role;
public:
    Employee(string ID, string n, string r) {
        employeeID = ID;
        name = n;
        role = r;
    }

    // -------------------------- Setters --------------------------
    void setEmployeeID(string ID) { employeeID = ID; }
    void setName(string n) { name = n; }
    void setRole(string r) { role = r; }

    // -------------------------- Getters --------------------------
    string getEmployeeID() const { return employeeID; }
    string getName() const { return name; }
    string getRole() const { return role; }

    // -------------------------- Order Processing (function) --------------------------
    void processOrder() {
        cout << "***************************************************" << endl;
        cout << name << " with the ID: " << employeeID
        << " is processing your order :) " << endl;
    }

    // -------------------------- Add Juice To Menu (function) --------------------------
    void addJuiceToMenu(string juiceName) {
        cout << "***************************************************" << endl;
        cout << juiceName << " added to the menu " << endl;
    }

    // -------------------------- Additional function --------------------------
    void displayInfo() const { //const since it will display employee info with out changes
        cout << "***************************************************" << endl;
        cout << "Employee Info" << endl;
        cout << "--------------"<< endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
    }
};

#endif
