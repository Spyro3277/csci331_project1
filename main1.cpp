/**
 * @file main.cpp
 * @author Bryan Erickson
 * @brief 
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */




#include <vector>
#include <iostream>
#include <fstream>
#include "record.h"
#include "state.h"

using namespace std; 

int main(){
    int index = 0;
    bool stateExists = 0;
    ifstream infile;
    string inputfile;
    state states[50];


    cout <<	"Please input a data-file:" << endl; 
    cin >> inputfile;

    infile.open(inputfile);

    vector<record> allRecords;

    record newRecord;

    while(!infile.eof())
    {
        newRecord.read(infile);
        stateExists = 0;
        for(int i = 0; i < 50; i++)
        {
            if(newRecord.getState() == states[i].getName())
            {
                states[i].addRecord(newRecord);
                stateExists = 1;
            }
        }
        if(!stateExists)
        {
            states[index].setName(newRecord.getState());
            states[index].addRecord(newRecord);
            index = index + 1;
        }

        allRecords.push_back(newRecord);
    }

}
