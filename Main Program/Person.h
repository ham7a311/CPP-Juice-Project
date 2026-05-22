#ifndef Person_H
#define Person_H

#include <iostream>
#include <string>
using namespace std;

// Parent class for Customer and Employee
class Person{
    protected:
        string name;
        string phoneNumber;

    public:
        // Constructor
        Person(string n, string phone = "00000000");

        //getters
        string getName() const;
        string getPhoneNumber() const;

        //setters
        void setName(string n);
        void setPhoneNumber(string phone);


        //display common person Info.
        virtual void displayPersonInfo() const;
};


#endif