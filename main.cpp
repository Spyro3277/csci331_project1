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





#include <iostream>
#include <fstream>
#include "record.h"
using namespace std; 

int main(){
    
    ifstream infile;
    string inputfile;

    cout <<	"Please input a data-file:" << endl; 
    cin >> inputfile;

    infile.open(inputfile);

    vector<record> allRecords;

    record newRecord;

    while(!infile.eof())
    {
        newRecord.read(infile);

        allRecords.push_back(newRecord);
    }

}