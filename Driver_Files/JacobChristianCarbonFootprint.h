#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H
#include <iostream>
using namespace std;
class CarbonFootPrint
{

public:
    virtual void getCarbonFootPrint() = 0;
    //Virtual destructor to prevent undefined behavior,
    //guarantees all constructors are properly destroyed.
    virtual ~CarbonFootPrint(){}



};
#include "JacobChristianBicycle.h"
#include "JacobChristianBuilding.h"
#include "JacobChristianTextile.h"
#endif // CARBONFOOTPRINT_H
