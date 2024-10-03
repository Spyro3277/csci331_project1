/**
 * @file record.cpp
 * @author Bryan Erickson
 * @brief Driver file for record class
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "record.h"
#include <fstream>

void record::read(istream& infile)
{
    infile >> zip >> city >> state >> county  >> lat>> longi;
}

void record::write(ostream& outfile)
{
    outfile<< zip << " " << city << " " << state << " " << county << " " << lat << " " << longi << endl;
}