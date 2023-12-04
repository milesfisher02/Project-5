#include "Dogs.h"
#include <iostream>
#include <fstream>

using namespace std;

Dogs::Dogs(const string& file_name) : total_dogs(0) {
    if (load_data(file_name)) {
        display_menu();
    } else {
        cerr << "Failed to load data from file." << endl;
    }
}

bool Dogs::load_data(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(", ");
        if (pos != string::npos) {
            string country = line.substr(0, pos);
            int population = stoi(line.substr(pos + 2));
            dogData[country] = population;
            total_dogs += population;
        }
    }
    file.close();
    return true;
}

void Dogs::display_menu() {
    while (true) {
        cout << "Choice Menu:" << endl;
        cout << "1. The total number of dogs in the world" << endl;
        cout << "2. Number of dogs for a specific country" << endl;
        cout << "3. Exit" << endl << endl;

        cout << "Enter a choice  (1, 2, or 3): ";
        int choice;
        cin >> choice;
        cout << endl << endl;

        switch (choice) {
            case 1:
                cout << "Total number of dogs in the world: " << total_dogs << endl;
                break;
            case 2: {
                string country;
                cout << "Enter the country name: ";
                cin.ignore();
                getline(cin, country);
                cout << endl;

                try {
                    int population = dogData.at(country);
                    cout << "The number of dogs in " << country << " is : " << population << endl;
                } catch (const out_of_range& e) {
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
