#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "record.h"
#include "state.h"
#include <iomanip>

using namespace std;


int main() {
    int index = 0;
    bool stateExists = false;
    ifstream infile;
    string inputfile;
    state states[50];

    cout << "Please input a data-file:" << endl; 
    cin >> inputfile;

    infile.open(inputfile);

    vector<record> allRecords;
    string line;

    while (getline(infile, line)) { // Read line by line from the CSV
        record newRecord;
        newRecord.readFromCSV(line); // Use the new method to read from CSV
        stateExists = false;
        for (int i = 0; i < index; i++) {
            if (newRecord.getState() == states[i].getName()) {
                states[i].addRecord(newRecord);
                stateExists = true;
                break; // Exit loop early if state is found
            }
        }

        if (!stateExists && index < 50) { // Ensure not to exceed array size
            states[index].setName(newRecord.getState());
            states[index].addRecord(newRecord);
            index++;
        }

        allRecords.push_back(newRecord);
    }

    // Output state information
    cout << "State     Easternmost        Westernmost        Northernmost        Southernmost" << endl;
    for (int i = 0; i < index; i++) {
        cout << states[i].getName() 
             << "         " << states[i].getnorthZIP() 
             << "              " << states[i].getsouthZIP() 
             << "              " << states[i].geteastZIP() 
             << "              " << states[i].getwestZIP() << endl;
    }

    return 0;
}
