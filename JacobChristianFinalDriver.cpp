
// Test program for CarbonFootprint and implementing classes.
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <stdlib.h> //for exit()
#include "JacobChristianCarbonFootprint.h"

using namespace std;

void createSquareFootageFile();
void readAndWriteSquareFootageFile(unique_ptr<CarbonFootPrint> &);

int main()
{
    //creating the original squareFootage file
    createSquareFootageFile();

    //creating a vector of unique_ptrs to abstract class, each with
    //a derived class. Initialized Building to zero, will increment
    //to push
    vector<unique_ptr<CarbonFootPrint>> carbonAmounts;
    carbonAmounts.push_back(unique_ptr<CarbonFootPrint>(new Bicycle()));
    carbonAmounts.push_back(unique_ptr<CarbonFootPrint>(new Textile()));
    //Initialized with 0, will be replaced once looped through
    carbonAmounts.push_back(unique_ptr<CarbonFootPrint>(new Building(0)));

    //call each individual getCarbonFunction (passing 2nd element through a function)
    carbonAmounts[0]->getCarbonFootPrint();
    carbonAmounts[1]->getCarbonFootPrint();
    readAndWriteSquareFootageFile(carbonAmounts[2]);
    return 0;
}

void createSquareFootageFile()
{
    ofstream square_footage;
    square_footage.open("squareFootage.txt");
    if(!square_footage)
    {
        cout << "File not found.";
        exit(EXIT_FAILURE);
    }
    for (int i=1; i < 101; ++i)
        square_footage << i * 100 << '\n';
    square_footage.flush();
    square_footage.close();
}

void readAndWriteSquareFootageFile(unique_ptr<CarbonFootPrint> &obj)
{
    fstream readFile,
            writeFile;
    string squareFoot;
    int squareFootInt;
    readFile.open("squareFootage.txt", ios::in);
    writeFile.open("squareFootageCarbonFootPrint.txt", ios::out);

    if((!readFile) || (!writeFile))
    {
        cout << "File not found.";
        exit(EXIT_FAILURE);
    }
    writeFile << "--------Sq. Ft.--------\t\t--------CO2 Output--------" << endl;
    while(readFile >> squareFoot)
    {
        squareFootInt = stoi(squareFoot);
        writeFile << '\t' << right << setw(5) << squareFootInt << "\t\t\t\t"
                  << right << setw(7) << squareFootInt * (50 + 20 + 47 + 17)
                  << endl;
        obj.reset(new Building(squareFootInt));
        obj->getCarbonFootPrint();

    }
    readFile.close();
    writeFile.close();
}

/* Captured output is located in "JacobChristianExam3Part2Output.txt" */
