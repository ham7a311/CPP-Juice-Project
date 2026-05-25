#include "Menu.h"


void Menu::showMenu() const{
    cout << "Available Juices:" << endl;
            for(int i = 0; i < availableJuice.size(); i++){
                availableJuice[i].displayJuiceInfo();  
                cout << endl;
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



string Menu::getJuiceName(string name) {
    for(auto juice: availableJuices) {
        if(juice == name) {
            return juice;
        }
    }
    
}
