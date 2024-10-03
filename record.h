/**
 * @file record.h
 * @author Bryan Erickson
 * @brief Header file for record class
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <fstream>
using namespace std;
#ifndef RECORDCLASS
#define RECORDCLASS

class record{

    private:

        //Data values used in a record
        int zip;
        string city, state, county;
        float lat, longi;

        public:
        
        /**
         * @brief Construct a default record object
         * 
         * @return A default record object
         * 
         */
        record(int z = 0, string c = "None", string s = "None", string co = "None", float la = 0.0, float lo = 0.0)
        {
            zip = z;
            city = c;
            state = s;
            county = co;
            lat = la;
            longi = lo;
        }

        /**
         * @brief Get the Zip object
         * 
         * @return zip code
         */
        int getZip() const {return zip;}

        /**
         * @brief Get the City object
         * 
         * @return city
         */
        string getCity() const {return city;}

        /**
         * @brief Get the State object
         * 
         * @return state
         */
        string getState() const {return state;}

        /**
         * @brief Get the County object
         * 
         * @return county
         */
        string getCounty() const {return county;}

        /**
         * @brief Get the Latitude object
         * 
         * @return latitude
         */
        float getLatitude() const {return lat;}

        /**
         * @brief Get the Longitude object
         * 
         * @return longitude
         */
        float getLongitude() const {return longi;}

        /**
         * @brief Reads the data from istream
         * 
         */
        void read(istream&);

        /**
         * @brief Writes the data to ostream
         * 
         */
        void write(ostream&);

        /**
         * @brief Overloads the "<" operator based on the latitude value
         * 
         * @param r 
         * @return true 
         * @return false 
         */
        bool operator<(const record& r) const{
            return lat < r.lat;
            }

        
};


        


        

#endif