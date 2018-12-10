// Author:				Jacob Christian
// Assignment Number:   Exam 3, part 2
// File Name:			JacobChristianLabBicycle.h
// Course/Section:      COSC 1337 Section 014
// Date:                December 13th, 2018
// Instructor:          Dr. Bernard Ku

// Bicycle.h
// Calculate the carbon footprint of a bicycle.
#ifndef TEXTILE_H
#define TEXTILE_H


#include <iostream>
#include "JacobChristianCarbonFootprint.h"

using namespace std;

// bicycle class that prints 0g of CO2
class Textile : public CarbonFootPrint
{
public:
    int menuChoice;
    virtual void getCarbonFootPrint() override
    {
        do {
            cout << "Select a textile for information:\n1)cotton\n2)nylon"
                "\n3)PET(a.k.a. synthetic fleece)\n4)Wool\n";
            cin >> menuChoice;
            cin.clear();
            cin.ignore(256,'\n');
            switch(menuChoice)
            {
                case 1:
                    cout << "Cotton produces 8g of carbon per Kg of material made." << endl;
                    break;
                case 2:
                    cout << "Nylon produces 5.43g of carbon per Kg of material made." << endl;
                    break;
                case 3:
                    cout << "PET produces 5.55g of carbon per Kg of material made." << endl;
                    break;
                case 4:
                    cout << "Wool produces 5.48g of carbon per Kg of material made." << endl;
                    break;
                default:
                    cout << "Invalid Response, please re-enter your choice." << endl;
            }
        }while(menuChoice < 1 || menuChoice > 4 || cin.fail());
    }
};

#endif //TEXTILE_H

