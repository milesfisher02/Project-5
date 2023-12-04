#include "Dogs.h"
#include <iostream>
#include <fstream>

using namespace std;

Dogs::Dogs(const string& file_name) : total_dogs(0)
{
    load_data(file_name);
}

void Dogs::load_data(const string& file_name)
{
    ifstream file(file_name);
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        size_t pos = line.find(", ");
        if (pos != string::npos)
        {
            string country = line.substr(0, pos);
            int population = stoi(line.substr(pos + 2));
            dogData[country] = population;
            total_dogs += population;
        }
    }
    file.close(); // Closing file
}

void Dogs::display_menu()
{
    while (true)
    {
        // Menu prompt
        cout << endl << "Choice Menu:" << endl;
        cout << "1. The total number of dogs in the world" << endl;
        cout << "2. Number of dogs for a specific country" << endl;
        cout << "3. Exit" << endl << endl;

        // Menu selection
        cout << "Enter a choice  (1, 2, or 3): ";
        int choice;
        cin >> choice;
        cout << endl;
        
        if (!choice = int)
        {
            cout << "Please select a number 1, 2, or 3"
        }
        else if (!choice = )
        {
            !choice
        }
        
        // Menu selection switch-statement
        switch (choice)
        {
            case 1:
                cout << "Total number of dogs in the world: " << total_dogs << endl;
                break;
            case 2:
            {
                string country;
                cout << "Enter the country name: ";
                cin.ignore();
                getline(cin, country);

                try
                {
                    int population = dogData.at(country);
                    cout << endl;
                    cout << "Number of dogs in " << country << ": " << population << endl;
                }
                catch (const out_of_range& e)
                {
                    cerr << "Country not found in the data." << endl;
                }
                break;
            }
            case 3:
                return;
            default:
                cout << "Invalid choice. Select another option." << endl;
                break;
        }
    }
}
