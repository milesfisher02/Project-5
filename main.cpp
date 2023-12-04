/* Programming Assignment #5
Name: Miles Fisher
Class: CS 250
School: St. Thomas Aquinas College
Program Description: A program that inputs a file with the amount of dogs within the country and the world and
displays a menu with choices of what the user wants to see... total nnumber of dogs in the world,
or dogs in a given country */

#include "Dogs.h"
#include <iostream>

using namespace std;

int main()
{
    string inputFile;
    cout << "Enter file name: ";
    cin >> inputFile;
    cout << endl;

    Dogs dogs_instance(inputFile);
    dogs_instance.display_menu();

    return 0;
}
