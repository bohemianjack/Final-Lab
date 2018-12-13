#include <vector>                           //to store dynamic classes in a vector
#include <memory>                           //for unique_ptr
#include <fstream>                          //for reading/writing files
#include <string>                           //for stoi()
#include <stdlib.h>                         //for exit()
#include "JacobChristianCarbonFootprint.h"  //all .h files of classes are directed into here

//namespace declaration
using namespace std;

//function header
void createSquareFootageFile();
void readAndWriteSquareFootageFile(unique_ptr<CarbonFootPrint> &);

int main()
{
    //creating the original squareFootage file
    createSquareFootageFile();

    //creating a vector of unique_ptrs to abstract class, each with
    //a derived class. Initialized Building to zero, will increment
    //when put through function. vector.emplace_back is used vs.
    //vector.push_back because emplace_back calls the constructor
    //for you implicitly.
    vector<unique_ptr<CarbonFootPrint>> carbonAmounts;
    carbonAmounts.emplace_back(new Bicycle());
    carbonAmounts.emplace_back(new Textile());
    carbonAmounts.emplace_back(new Building(0));

    //call each individual getCarbonFunction (passing 2nd element through a function)
    carbonAmounts[0]->getCarbonFootPrint();
    carbonAmounts[1]->getCarbonFootPrint();
    readAndWriteSquareFootageFile(carbonAmounts[2]);
    cout << "\nFor a nifty chart explaining the CO2 amounts per square foot, please see\n"
         << "file 'squareFootageCarbonFootPrint.txt' located in the file directory.\n";
    return 0;
}

/**********************************************************************************************
*                               void createSquareFootageFile()                                *
*   void function to create a .txt file with integers, starting with 100, ending with 10000,  *
*   and goes in increments of 100. If the file can't be created, it'll display an error       *
*   message and exit the program. Otherwise, it loops through, writes each number with a      *
*   newline character, then closes the file to pass through readAndWriteSquareFootageFile()   *
**********************************************************************************************/
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

/**********************************************************************************************
*           void readAndWriteSquareFootageFile(unique_ptr<CarbonFootPrint> &obj)              *
*   a void function that passes in a unique_ptr class reference. This is a Building class     *
*   that starts out with the value zero, as defined in the constructor on line 36. The        *
*   function uses fstream to both read the file created in createSquareFootageFile(), and     *
*   write a new file. If either the reading file is not found, or the writing file is fails   *
*   to create a new file, it'll call EXIT_FAILURE and end the program. Otherwise, it creates  *
*   a table in "squareFootageCarbonFootPrint.txt", which will be created in the directory.    *
*   It then takes each line, extracts it to a string class object, converts it to an int,     *
*   and writes it into the writeFile (after some manipulation). Then it displays, in a 2nd    *
*   column, the equation found in JacobChristianBuilding.h, and displays the number. Then,    *
*   the obj within the vector is reset (found in <memory>) and that object is destroyed and   *
*   replaced with whatever value was read through the extraction operator.                    *
*   getCarbonFootprint() is called to display the void message found in that class. The files *
*   are then closed. The console should output a text-rich message with the CO2 values, and   *
*   "squareFootageCarbonFootPrint.txt" will have a tabled chart with those values to view.    *
**********************************************************************************************/
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
    writeFile << "-----------------------------------------------------" << endl;
    writeFile << "|--------Sq. Ft.--------||--------CO2 Output--------|" << endl;
    writeFile << "|-----------------------||--------------------------|" << endl;
    while(readFile >> squareFoot)
    {
        squareFootInt = stoi(squareFoot);
        writeFile << "|       " << right << setw(5) << squareFootInt << "\t\t||         "
                  << right << setw(7) << squareFootInt * (50 + 20 + 47 + 17) << "          |"
                  << "\n|-----------------------||--------------------------|" << endl;
        obj.reset(new Building(squareFootInt));
        obj->getCarbonFootPrint();

    }
    readFile.close();
    writeFile.close();
}

/* Captured output is located in "JacobChristianExam3Part2Output.txt" */
