#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <stdexcept>
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
        
        
        // pure virtual(function = 0) to make it abstract, this function has to be overriden by another function in Cusstomer and Employee.
        // add '= 0' to make it not possible to create a seperate object from this class, because a Person is either a Customer and Employee, and you cant create a Person("Ahmed") or Person("Ahmed", "99483902" for example
        virtual void displayPersonInfo() const = 0;


        //Destructor
        virtual ~Person();
};


#endif
