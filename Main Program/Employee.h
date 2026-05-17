#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

// -------------------------- Base Class --------------------------
class Employee : public Person {
private:
    string employeeID;
    string role;


public:
    Employee(string ID, string n, string phone, string r);



    // -------------------------- Setters --------------------------
    void setEmployeeID(string ID);
    void setRole(string r);



    // -------------------------- Getters --------------------------
    string getEmployeeID() const;
    string getRole() const;



    // -------------------------- Order Processing (function) --------------------------
    void processOrder() const;



    // -------------------------- Add Juice To Menu (function) --------------------------
    void addJuiceToMenu(string juiceName) const;





    // -------------------------- Additional function --------------------------
    void displayEmployeeInfo() const;
};

#endif
