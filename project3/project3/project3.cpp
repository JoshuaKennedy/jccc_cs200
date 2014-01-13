//
//  project3.cpp
//
//  Created by Josh Kennedy on 11/22/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Global constants.
const int ORDER_VALUE = 500;
const int MAX_CELLS = 100;

// Function prototypes.
bool loadArrays(const char fileName[], long idArray[], int storeArray[], int qtyArray[], int& count, int maxCells);
void printArrays(ostream& w, const long idArray[], const int storeArray[], const int qtyArray[], int count);
bool extractData(const char newFileName[], long requestId, int baseQty, const long idArray[], const int storeArray[], const int qtyArray[], int count, int& newCount);

// Entry point to application.
int main(int argc, const char * argv[])
{
    // Variable declarations.
    string fileName, newFileName;
    long id[ORDER_VALUE];
    int store[ORDER_VALUE];
    int qty[ORDER_VALUE];
    int count = 0;
    int newCount = 0;
    ofstream outputFile;
    
    fileName = "/Users/joshuakennedy/Desktop/data.dat";
    newFileName = "/Users/joshuakennedy/Desktop/outputData.txt";
    
    // Let's read the file.
    if (!loadArrays(fileName.c_str(), id, store, qty, count, MAX_CELLS))
    {
        // If the count is zero and the loadArrays function returns false, then we didn't load the file.
        if (count == 0)
        {
            cerr << "Whoa! I couldn't open the file: " << fileName << " for input." << endl;
            exit(1);
        }
        else
        {
            // Otherwise, we loaded it, but there was more cells than allowed by MAX_CELLS.
            cerr << "There are more than " << MAX_CELLS << " in the file!" << endl;
            exit(2);
        }
    }
    else
    {
        cout << count << ((count > 1) ? " lines" : " line") << " loaded!" << endl;
    }
    
    // Let's output the data to a file.
    
    // Create the output stream.
    outputFile.open(newFileName);
    
    // Check to see if it opened ok.
    if (outputFile.fail())
    {
        cerr << "Whoa! I couldn't open the file: " << newFileName << " for output." << endl;
        exit(4);
    }
    
    // Call the printArrays function to print it out to the file.
    printArrays(outputFile, id, store, qty, count);
    
    // Close it, so we can access it from extractData.
    outputFile.close();
    
    // Get the id number from user.
    int idNumber = 0;
    
    cout << "Enter id number to look up: ";
    cin >> idNumber;
    
    if (!extractData(newFileName.c_str(), idNumber, ORDER_VALUE, id, store, qty, count, newCount))
    {
        if (newCount == 0)
        {
            cerr << "Whoa! I couldn't open the file: " << newFileName << " for output." << endl;
            exit(5);
        }
    }
    else
    {
        cout << newCount << ((newCount > 1) ? " lines" : " line") << " written." << endl;
    }
    
    return 0;
}

// Function implementations.
bool loadArrays(const char fileName[], long idArray[], int storeArray[], int qtyArray[], int& count, int maxCells)
{
    // Variable declarations.
    ifstream fileIn;
    
    // Set the count equal to zero to start.
    count = 0;
    
    // Load the file and check to see if it opened ok.
    fileIn.open(fileName);
    
    if (fileIn.fail())
    {
        // Since we couldn't find the file, didn't have permission to, or another process has it open, we return false.
        return false;
    }
    else
    {
        // Now that it opened ok, let's parse this data! :-)
        
        // This is the fancy part.
        // We essentially just read one line at a time, and put each column in it's own array.
        // We also check to make sure we're not approaching the maximum cell count.
        while (fileIn >> idArray[count] >> storeArray[count] >> qtyArray[count] && count < maxCells)
        {
            count++;
        }
        
        // Close file stream.
        fileIn.close();

        // Since we read the file ok, we can safely return true to signify the success of this operation.
        return ((count < maxCells) ? true : false);
    }
}

void printArrays(ostream& w, const long idArray[], const int storeArray[], const int qtyArray[], int count)
{
    for (int i = 0; i < count; i++)
    {
        w << "Store " << storeArray[i] << " has " << qtyArray[i] << ((qtyArray[i] > 1) ? " units" : " units") << " of " << idArray[i] << " in stock." << endl;
    }
}

bool extractData(const char newFileName[], long requestId, int baseQty, const long idArray[], const int storeArray[], const int qtyArray[], int count, int& newCount)
{
    // Declare and open output file stream.
    ofstream output;
    output.open(newFileName, ofstream::out | ofstream::app);
    
    // Check to see if it opened ok.
    if (output.fail())
    {
        newCount = 0;
        return false;
    }
    else
    {
        // Go through all of the data that was loaded.
        for (int i = 0; i < count; i++)
        {
            // We check to see if we have a match for the product id, and if we don't have enough of the base quantity.
            if (requestId == idArray[i] && baseQty > qtyArray[i])
            {
                newCount++;
                
                output << "Store # " << storeArray[i] << " needs to order " << (baseQty - qtyArray[i]) << (((baseQty - qtyArray[i]) > 1) ? " more units" : " more unit") << " of " << idArray[i] << endl;
            }
        }
        
        output.close();
        
        return true;
    }
}

/* Output:
 
 *** FROM INPUT FILE ***
 
 400000 12340 500
 400000 12341 350
 400000 12342 0
 400000 12343 1000
 400000 12344 500
 
 400001 12340 500
 400001 12341 350
 400001 12342 0
 400001 12343 1000
 400001 12344 500
 
 400002 12340 500
 400002 12341 350
 400002 12342 0
 400002 12343 1000
 400002 12344 500
 
 400003 12340 500
 400003 12341 350
 400003 12342 0
 400003 12343 1000
 400003 12344 500
 
 400004 12340 500
 400004 12341 350
 400004 12342 0
 400004 12343 1000
 400004 12344 500
 
 *** FROM PROGRAM ***
 
 25 lines loaded!
 Enter id number to look up: 400004
 2 lines written.
 Program ended with exit code: 0
 
 *** FROM OUTPUT FILE ***
 
 Store 12340 has 500 units of 400000 in stock.
 Store 12341 has 350 units of 400000 in stock.
 Store 12342 has 0 units of 400000 in stock.
 Store 12343 has 1000 units of 400000 in stock.
 Store 12344 has 500 units of 400000 in stock.
 Store 12340 has 500 units of 400001 in stock.
 Store 12341 has 350 units of 400001 in stock.
 Store 12342 has 0 units of 400001 in stock.
 Store 12343 has 1000 units of 400001 in stock.
 Store 12344 has 500 units of 400001 in stock.
 Store 12340 has 500 units of 400002 in stock.
 Store 12341 has 350 units of 400002 in stock.
 Store 12342 has 0 units of 400002 in stock.
 Store 12343 has 1000 units of 400002 in stock.
 Store 12344 has 500 units of 400002 in stock.
 Store 12340 has 500 units of 400003 in stock.
 Store 12341 has 350 units of 400003 in stock.
 Store 12342 has 0 units of 400003 in stock.
 Store 12343 has 1000 units of 400003 in stock.
 Store 12344 has 500 units of 400003 in stock.
 Store 12340 has 500 units of 400004 in stock.
 Store 12341 has 350 units of 400004 in stock.
 Store 12342 has 0 units of 400004 in stock.
 Store 12343 has 1000 units of 400004 in stock.
 Store 12344 has 500 units of 400004 in stock.
 Store # 12341 needs to order 150 more units of 400004
 Store # 12342 needs to order 500 more units of 400004
 
 */

