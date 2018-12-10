// Author:				Jacob Christian
// Assignment Number:   Exam 3, part 2
// File Name:			JacobChristianBuilding.h
// Course/Section:      COSC 1337 Section 014
// Date:                December 13th, 2018
// Instructor:          Dr. Bernard Ku

// Building.h
// Calculate the carbon footprint of a building.
#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <iomanip>
#include "JacobChristianCarbonFootprint.h"

using namespace std;

// building class that takes sqft and puts it into the formula for calculation
class Building : public CarbonFootPrint
{
private:
    int squareFeet; // square footage of building (switched to long long)
public:
    Building(int sf) : squareFeet(sf) { }

    //Original website link down. Basing formula off of slide 10-45
    virtual void  getCarbonFootPrint() override
    {
        cout << "Building with " << setw(5) << squareFeet << " square feet: "
             << setw(7) << squareFeet * (50 + 20 + 47 + 17) << " g of CO2" << endl;
    }
};

#endif //BUILDING_H



