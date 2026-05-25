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
        void showMenu() const;             // const for two reasons: 1) displayJuiceInfo is const in Jucie.h so to use it here ShowMenu must be const. 2) the function it self only print Info. about the Juice, not changing any thing.




        // A function to add a new juice to the menu
        void addJuice(Juice j);   //Adds a new juice object to the end of the availableJuices list.



        //A function to remove a juice based on its name.
        void removeJuice(string name);


        void searchJuice(string name);

        // getter for returning juice name, this will be used in main.cpp
        string getJuiceName(string name);
};



#endif
