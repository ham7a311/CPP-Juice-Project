#include "Person.h"


// Constructor
Person::Person(string n, string phone) {
    if (n == "") {
        throw invalid_argument("Name cannot be empty.");
    }

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

// Destructor
Person::~Person() {
}