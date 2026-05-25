#include "Menu.h"
#include <stdexcept>


void Menu::showMenu() const {
    cout << "Available Juices:\n";

    for (int i = 0; i < availableJuices.size(); i++) {
        cout << i + 1 << ". " << endl;
        availableJuices[i].displayJuiceInfo();
        cout << "--------------------------------\n";
    }
}



void Menu::addJuice(Juice j){
    availableJuices.push_back(j);
}



void Menu::removeJuice(string name){
    for(int i = 0; i < availableJuices.size(); i++){
                if(availableJuices[i] == name){
                    availableJuices.erase(availableJuices.begin() + i);
                    cout << "Juice deleted." << endl; 
                    return;
                }
    }
    cout << "Juice not found!!" << endl;
}




void Menu::searchJuice(string name){
    for(int i = 0; i < availableJuices.size(); i++){
                if(availableJuices[i] == name){
                    cout << "Juice found." << endl;
                    availableJuices[i].displayJuiceInfo();
                    return;
                }
    }
    cout << "Juice not found!!" << endl;
}


// return a juice object from menu that has the same name as "name" which is provided by user
// throw an invalid argument if juice not found
Juice Menu::getJuice(string name) {
    for(auto juice: availableJuices) {
        if(juice == name) {
            return juice;
        }
    }

    throw invalid_argument("Juice name not found.");
    
}


Juice Menu::getJuiceUsingIndex(int index) {
    if (index < 1 || index > availableJuices.size()) {
        throw invalid_argument("Invalid Juice selection, there is no juice with that number");
    }
    return availableJuices[index-1];
}
