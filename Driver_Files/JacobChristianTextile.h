#ifndef TEXTILE_H
#define TEXTILE_H

#include "JacobChristianCarbonFootprint.h"

using namespace std;

// textile class that gives a switch statement to the user to give them information
// about a clothing material and how much carbon is emitted per kg.
class Textile : public CarbonFootPrint
{
private:
    int menuChoice;
public:
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
    ~Textile(){} //Destructor for derived class
};

#endif //TEXTILE_H
