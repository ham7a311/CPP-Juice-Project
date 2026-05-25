#include "Menu.h"


void Menu::showMenu() const {
    cout << "Available Juices:\n";

    for (int i = 0; i < availableJuices.size(); i++) {
        cout << i + 1 << ". " << endl;
        availableJuices[i].displayJuiceInfo();
        cout << "--------------------------------\n";
    }
}



void Menu::addJuice(Juice j){
    availableJuice.push_back(j);
}



void Menu::removeJuice(string name){
    for(int i = 0; i < availableJuice.size(); i++){
                if(availableJuice[i] == name){
                    availableJuice.erase(availableJuice.begin() + i);
                    cout << "Juice deleted." << endl; 
                    return;
                }
    }
    cout << "Juice not found!!" << endl;
}




void Menu::searchJuice(string name){
    for(int i = 0; i < availableJuice.size(); i++){
                if(availableJuice[i] == name){
                    cout << "Juice found." << endl;
                    availableJuice[i].displayJuiceInfo();
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
