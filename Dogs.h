#ifndef DOGS_H
#define DOGS_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Dogs {
private:
    unordered_map<string, int> dogData;
    int total_dogs;

public:
    Dogs(const string& file_name);
    void load_data(const string& file_name);
    void display_menu();
};

#endif /* DOGS_H */
