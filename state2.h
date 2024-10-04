/**
 * @file state.h
 * @author Noah Matzke
 * @brief header file for state class
 * @version 1.0
 * @date 2024-10-03
 * 
 */

#include <iostream>
#include <fstream>
#include "record.h"

using namespace std;
#ifndef STATECLASS
#define STATECLASS

class state
{
    private:
    string name;
    string northZIP, southZIP, eastZIP, westZIP;
    float northLAT, southLAT, eastLONG, westLONG;

    public:

    state(string n = "None", string nz = "0", string sz = "0", string ez = "0", string wz = "0", float nl = 0.0, float sl = 0.0, float el = 0.0, float wl = 0.0)
    {
        name = n;
        northZIP = nz;
        southZIP = sz;
        eastZIP = ez;
        westZIP = wz;
        northLAT = nl;
        southLAT = sl;
        westLONG = wl;
        eastLONG = el;
    }

    string getName() const {return name;}

    string getnorthZIP() const {return northZIP;}

    string getsouthZIP() const {return southZIP;}

    string getwestZIP() const {return westZIP;}

    string geteastZIP() const {return eastZIP;}

    float getnorthLAT() const {return northLAT;}

    float getsouthLAT() const {return southLAT;}

    float geteastLONG() const {return eastLONG;}

    float getwestLONG() const {return westLONG;}

    void setName(string na)
    {
        name = na;
    }

    void setnorthZIP(string i)
    {
        northZIP = i;
    }

    void setsouthZIP(string i)
    {
        southZIP = i;
    }

    void setwestZIP(string i)
    {
        westZIP = i;
    }

    void seteastZIP(string i)
    {
        eastZIP = i;
    }

    void setnorthLAT(float f)
    {
        northLAT = f;
    }

    void setsouthLAT(float f)
    {
        southLAT = f;
    }

    void seteastLONG(float f)
    {
        eastLONG = f;
    }

    void setwestLONG(float f)
    {
        westLONG = f;
    }

    void addRecord(record r)
    {
        if((eastLONG == 0) || (westLONG == 0) || (northLAT == 0) || (southLAT == 0))
        {
            eastLONG = r.getLongitude();
            westLONG = r.getLongitude();
            northLAT = r.getLatitude();
            southLAT = r.getLatitude();
        }
       if(r.getLongitude() > eastLONG)
        {
            eastLONG = r.getLongitude();
            eastZIP = r.getZip();
        }
       if(r.getLongitude() < westLONG)
        {
            westLONG = r.getLongitude();
            westZIP = r.getZip();
        }
       if(r.getLatitude() > northLAT)
        {
            northLAT = r.getLatitude();
            northZIP = r.getZip();
        }
       if(r.getLatitude() < southLAT)
        {
            southLAT = r.getLatitude();
            southZIP = r.getZip();
        }
    }
};




#endif
