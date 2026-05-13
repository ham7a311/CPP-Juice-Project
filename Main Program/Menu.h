#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<vector>        //better to use instead of an array so we can add and delete juices without any problems
#include"Juice.h"
using namespace std;

// Menu class to manage a collection of juice objs available for sale.
class Menu{
    private:
        vector<Juice> availableJuice;          //Dynamic list to store the different juice objects.

    public:
        // A fucntion to print the menu
        void showMenu() const{               // const for two reasons: 1) displayJuiceInfo is const in Jucie.h so to use it here ShowMenu must be const. 2) the function it self only print Info. about the Juice, not changing any thing.
            cout << "Available Jucies:" << endl;
            for(int i = 0; i < availableJuice.size(); i++){
                availableJuice[i].displayJuiceInfo();       //goes through the list and calls the display function for each juice
                cout << endl;
            }
        }



        // A function to add a new juice to the menu
        void addJuice(Juice j){
            availableJuice.push_back(j);   //Adds a new juice object to the end of the availableJuices list.
        }


        //A function to remove a juice based on its name.
        void removeJuice(string name){
            for(int i = 0; i < availableJuice.size(); i++){
                if(availableJuice[i].getJuiceName() == name){
                    availableJuice.erase(availableJuice.begin() + i);
                    cout << "Jucie deleted." << endl; 
                    return;
                }
            }
            cout << "Juice not found!!" << endl;
        }


        void searchJuice(string name){
            for(int i = 0; i < availableJuice.size(); i++){
                if(availableJuice[i].getJuiceName() == name){
                    cout << "Juice found." << endl; 
                    availableJuice[i].displayJuiceInfo();
                    return;
                }
            }
            cout << "Juice not found!!" << endl;
        }
};



#endif
