//
//  workerStructure.cpp
//
//  Created by Josh Kennedy on 9 November 2013.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>

using namespace std;

// Data structure definition.
struct Worker
{
    int idNumber;
    unsigned int hoursWorked;
    double payRate;
    double earned;
};

// Constant Definitions
const int maxNumberOfWorkers = 50;

// Function prototypes
void fillData(Worker& workerObject, int id, unsigned int hours, double rate); // For a singular Worker object.
void fillData(Worker* workerObjects, const int* ids, const unsigned int* hours, const double* rates, int howMany); // For an array of Worker objects.

void calculateData(Worker& workerObject); // For a singular Worker object.
void calculateData(Worker* workerObjects, int howMany); // For an array of Worker objects.

void outputData(const Worker& workerObject, ostream& output); // For a singular Worker object.
void outputData(const Worker* workerObjects, ostream& output, int howMany); // For an array of Worker objects.

int numberOfWorkersWhoWorkedOvertime(const Worker* workerObjects, int howMany); // For an array of Worker objects.

// Entry point of application.
int main(int argc, const char * argv[])
{
    //////////////
    //  Part I  //
    //////////////
    
    cout << "PART I\n-----------------" << endl;
    
    // Variable Declarations.
    int id;
    unsigned int hours;
    double rate;
    Worker myWorker;
    
    // Prompt user and get their input.
    cout << "Enter worker id: ";
    cin >> id;
    
    cout << "Enter pay rate: ";
    cin >> rate;
    
    cout << "Enter number of hours worked: ";
    cin >> hours;
    
    // Put the data in the structure.
    fillData(myWorker, id, hours, rate);
    
    // Calculate the earned pay.
    calculateData(myWorker);
    
    // Output all of the attributes in the structure.
    outputData(myWorker, cout);
    
    ///////////////
    //  Part II  //
    ///////////////
    
    cout << endl << "PART II\n-----------------" << endl;
    
    // Variable declarations and initializations.
    Worker* myWorkers = new Worker[maxNumberOfWorkers];
    int numWorkers = 0;
    
    int ids[maxNumberOfWorkers] = { 0 };
    unsigned int multiHours[maxNumberOfWorkers] = { 0 };
    double rates [maxNumberOfWorkers] = { 0 };
    
    // Get number of workers.
    cout << "How many workers (1 - 50): ";
    cin >> numWorkers;
    
    // Fill the arrays with data.
    for (int i = 0; i < numWorkers; i++)
    {
        cout << "Enter worker id: ";
        cin >> ids[i];
        
        cout << "Enter pay rate: ";
        cin >> rates[i];
        
        cout << "Enter hours worked: ";
        cin >> multiHours[i];
        
        cout << endl;
    }
    
    // Put this data in the Worker array.
    fillData(myWorkers, ids, multiHours, rates, numWorkers);
    
    // Calculate the amount earned for the workers.
    calculateData(myWorkers, numWorkers);
    
    // Output the data.
    outputData(myWorkers, cout, numWorkers);
    
    // De-initialize memory from arrays.
    delete[] myWorkers;
    
    return 0;
}

///////
// Singular Worker object method implementations
///////

void fillData(Worker& workerObject, int id, unsigned int hours, double rate)
{
    workerObject = { id, hours, rate };
}

void calculateData(Worker& workerObject)
{
    workerObject.earned = ((workerObject.hoursWorked > 40) ? (((workerObject.hoursWorked - 40) * workerObject.payRate * 1.5) + (workerObject.payRate * 40)) : (workerObject.hoursWorked * workerObject.payRate));
}

void outputData(const Worker& workerObject, ostream& output)
{
    output << "Worker #" << workerObject.idNumber << endl << '\t' << "Hours Worked:\t" <<  workerObject.hoursWorked << endl << '\t' << "Pay Rate:\t" << workerObject.payRate << endl << '\t' << "Earned:\t" << workerObject.earned << endl;
}

///////
// Array of Worker objects method implementations
///////

void fillData(Worker* workerObjects, const int* ids, const unsigned int* hours, const double* rates, int howMany)
{
    for (int i = 0; i < howMany; i++)
    {
        fillData(*workerObjects, *ids, *hours, *rates);
        
        workerObjects++;
        ids++;
        hours++;
        rates++;
    }
}

void calculateData(Worker* workerObjects, int howMany)
{
    for (int i = 0; i < howMany; i++)
    {
        calculateData(*workerObjects);
        
        workerObjects++;
    }
}

void outputData(const Worker* workerObjects, ostream& output, int howMany)
{
    for (int i = 0; i < howMany; i++)
    {
        outputData(*workerObjects, output);
        
        cout << endl;
        
        workerObjects++;
    }
}

/* Output:
 
 PART I
 -----------------
 Enter worker id: 030871
 Enter pay rate: 12.10
 Enter number of hours worked: 20
 Worker #30871
 Hours Worked:	20
 Pay Rate:	12.1
 Earned:	242
 
 PART II
 -----------------
 How many workers (1 - 50): 3
 Enter worker id: 12345
 Enter pay rate: 24.20
 Enter hours worked: 40
 
 Enter worker id: 67890
 Enter pay rate: 36.30
 Enter hours worked: 60
 
 Enter worker id: 69
 Enter pay rate: 16.25
 Enter hours worked: 40
 
 Worker #12345
 Hours Worked:	40
 Pay Rate:	24.2
 Earned:	968
 
 Worker #67890
 Hours Worked:	60
 Pay Rate:	36.3
 Earned:	2541
 
 Worker #69
 Hours Worked:	40
 Pay Rate:	16.25
 Earned:	650
 
 Program ended with exit code: 0
 
 */

