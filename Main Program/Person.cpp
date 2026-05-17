#include "Person.h"


// Constructor
Person::Person(string n, string phone){
    name = n;
    phoneNumber = phone;   
}


// Getters
string Person::getName() const{
    return name;
}

string Person::getPhoneNumber() const{
    return phoneNumber;
}


// Setters
void Person::setName(string n){
    name = n;
}

void Person::setPhoneNumber(string phone){
    phoneNumber = phone;
}


//Display
void Person::displayPersonInfo() const{
    cout << "Name      : " << name << endl;
    cout << "Phone     : " << phoneNumber << endl;
}