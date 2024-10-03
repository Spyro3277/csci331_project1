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
#include <sstream>
#include <vector>
#include "record.h"
using namespace std; 





/**
 * @brief Main function
 * 
 * @return int 
 */
int main(){
    
    ifstream infile;
    string inputfile;

    vector<record> allRecords;

    record test1(501,"Holtsville","NY","Suffolk",40.8154,-73.0451),test2(1053,"Leeds","NY","Hampshire",42.3543,-72.7034),
    test3(3595,"Twin Mountain","NY","Coos",44.2689,-71.5471),test4(4449,"Hudson","NY","Penobscot",44.9914,-68.8878),
    test5(5658,"Marshfield","NY","Washington",44.3509,-72.354);

    allRecords.push_back(test1);
    allRecords.push_back(test2);
    allRecords.push_back(test3);
    allRecords.push_back(test4);
    allRecords.push_back(test5);


    /**
     * @brief Sorts the vecor from least latitude to most latitude
     */
    sort(allRecords.begin(), allRecords.end());

    cout <<	"Least Latitude:" << endl; 
    allRecords.front().write(cout);

    cout <<	"Most Latitude:" << endl; 
    allRecords.back().write(cout);

    /**
     * @brief Structure that compares the longitude of two records
     * @return The bool value found when comapring the value of two longitudes
     * 
     */
    struct sortLongitude{
        inline bool operator() (const record& struct1, const record& struct2)
    {
        return (struct1.getLongitude() < struct2.getLongitude());
    }
    };

    /**
     * @brief Sorts the vector by longitude
     */
    sort(allRecords.begin(), allRecords.end(), sortLongitude());

    cout <<	"Least Longitude:" << endl; 
    allRecords.front().write(cout);

    cout <<	"Most Longitude" << endl; 
    allRecords.back().write(cout);

 

    

    

  

} 

   


