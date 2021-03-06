// Bicycle.h
// Calculate the carbon footprint of a bicycle.
#ifndef BICYCLE_H
#define BICYCLE_H


#include <iostream>
#include "JacobChristianCarbonFootprint.h"

using namespace std;

// bicycle class that prints 0g of CO2
class Bicycle : public CarbonFootPrint
{
public:
   // Not counting the carbon used to make the bicycle,
   // a bike's carbon footprint is 0
   // http://www.livemint.com/2009/06/04230851/
   //    How-big-is-your-carbon-footpri.html?pg=1
   virtual void getCarbonFootPrint() {
      cout << "A bicycle produces 0 grams of carbon!" << endl;
   }
   ~Bicycle(){} //Destructor for subclass
};

#endif
