#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Employee : public Person {
private:
    string employeeID;
    string role;

public:
    // Constructor
    Employee(string ID, string n, string phone, string r);

    // Setters
    void setEmployeeID(string ID);
    void setRole(string r);

    // Getters
    string getEmployeeID() const;
    string getRole() const;

    // Functions
    void processOrder() const;
    void addJuiceToMenu(string juiceName) const;

    // Override display function from Person
    void displayPersonInfo() const override;
};

#endif