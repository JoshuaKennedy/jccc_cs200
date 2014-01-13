//
//  workerClass.cpp
//
//  Created by Josh Kennedy on 11/16/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

// Worker Class (CWorker) Definition
class CWorker
{
public:
    CWorker();
    int getId(void) const;
    int getHours(void) const;
    double getRate(void) const;
    double getEarned(void) const;
    
    void setId(int);
    void setHours(int);
    void setRate(double);
    void figureEarned(void); //pay time and one-half over 40
    
private:
    int idNumber;
    int hoursWorked;
    double hourlyRate;
    double earned;
};

// Non-object function prototypes.
void input(CWorker*& workers, int size);
void figure(CWorker*& workers, int size);
void output(ostream& output, CWorker* workers, int size);
int overtime(CWorker* workers, int size);

// Entry point definition.
int main(int argc, const char* argv[])
{
    cout << "~ PART I ~" << endl << endl;
    
    // Variable declarations.
    CWorker myWorker = CWorker();
    
    int id, hours;
    double rate;
    
    // Prompt and get user input.
    cout << "Employee ID Number: ";
    cin >> id;
    
    cout << "Employee Pay Rate: ";
    cin >> rate;
    
    cout << "Employee Hours Worked: ";
    cin >> hours;
    
    // Put the data in the object.
    myWorker.setId(id);
    myWorker.setRate(rate);
    myWorker.setHours(hours);
    
    // Calculate earned pay.
    myWorker.figureEarned();
    
    // Output it!
    cout << "Worker " << myWorker.getId() << ':' << "\n\tHours Worked: " << myWorker.getHours() <<  "\n\tHourly Rate: " << myWorker.getRate() << "\n\tTotal Earned: " << std::fixed << std::setprecision(2) << '$' << myWorker.getEarned() << endl;
    
    cout << endl << "~ PART II ~" << endl << endl;
    
    // Variable declarations
    CWorker* myWorkers;
    int howMany = 0;
    
    // Prompt user and get number of employees.
    cout << "How many employees: ";
    cin >> howMany;
    
    // Create array with howMany values.
    myWorkers = new CWorker[howMany];
    
    // Grab the input from the user.
    input(myWorkers, howMany);
    
    // Do the hokey-pokey.
    figure(myWorkers, howMany);
    
    // Output it to cout.
    output(cout, myWorkers, howMany);
    
    // Get the number of workers who worked overtime.
    int numOvertime = overtime(myWorkers, howMany);
    
    // Output it.
    cout << numOvertime << ((numOvertime > 1) ? " workers" : " worker") << " worked overtime." << endl;
    
    // Return success to the OS.
    return 0;
}

// Worker Class (CWorker) Constructor and Function Definitions

CWorker::CWorker()
{
    this->idNumber = 0;
    this->hoursWorked = 0;
    this->hourlyRate = 0.0;
    this->earned = 0;
}

int CWorker::getId() const
{
    return this->idNumber;
}

int CWorker::getHours() const
{
    return this->hoursWorked;
}

double CWorker::getRate() const
{
    return this->hourlyRate;
}

double CWorker::getEarned() const
{
    return this->earned;
}

void CWorker::setId(int id)
{
    this->idNumber = id;
}

void CWorker::setHours(int hours)
{
    this->hoursWorked = hours;
}

void CWorker::setRate(double rate)
{
    this->hourlyRate = rate;
}

void CWorker::figureEarned()
{
    this->earned = ((this->hoursWorked > 40) ? (((this->hoursWorked - 40) * this->hourlyRate * 1.5) + (this->hourlyRate * 40)) : (this->hoursWorked * this->hourlyRate));
}

// Non-object function definitions.

void input(CWorker*& workers, int size)
{
    for (int i = 0; i < size; i++)
    {
        CWorker myWorker = CWorker();
        int id, hours;
        double rate;
        
        cout << "Employee ID Number: ";
        cin >> id;
        
        cout << "Employee Pay Rate: ";
        cin >> rate;
        
        cout << "Employee Hours Worked: ";
        cin >> hours;
        
        myWorker.setId(id);
        myWorker.setRate(rate);
        myWorker.setHours(hours);
        
        workers[i] = myWorker;
        
        cout << endl;
    }
}

void figure(CWorker*& workers, int size)
{
    for (int i = 0; i < size; i++)
    {
        workers[i].figureEarned();
    }
}

void output(ostream& output, CWorker* workers, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Worker " << workers[i].getId() << ':' << "\n\tHours Worked: " << workers[i].getHours() <<  "\n\tHourly Rate: " << workers[i].getRate() << "\n\tTotal Earned: " << std::fixed << std::setprecision(2) << '$' << workers[i].getEarned() << endl << endl;
    }
}

int overtime(CWorker* workers, int size)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (workers[i].getHours() > 40)
            count++;
    }
    
    return count;
}

/* Output:
 
 ~ PART I ~
 
 Employee ID Number: 66
 Employee Pay Rate: 12
 Employee Hours Worked: 50
 Worker 66:
 Hours Worked: 50
 Hourly Rate: 12
 Total Earned: $660.00
 
 ~ PART II ~
 
 How many employees: 3
 Employee ID Number: 67
 Employee Pay Rate: 18
 Employee Hours Worked: 39
 
 Employee ID Number: 68
 Employee Pay Rate: 14.25
 Employee Hours Worked: 41
 
 Employee ID Number: 69
 Employee Pay Rate: 12
 Employee Hours Worked: 40
 
 Worker 67:
 Hours Worked: 39
 Hourly Rate: 18.00
 Total Earned: $702.00
 
 Worker 68:
 Hours Worked: 41
 Hourly Rate: 14.25
 Total Earned: $591.38
 
 Worker 69:
 Hours Worked: 40
 Hourly Rate: 12.00
 Total Earned: $480.00
 
 1 worker worked overtime.
 Program ended with exit code: 0
 
 */

