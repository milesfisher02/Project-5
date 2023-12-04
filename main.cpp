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
