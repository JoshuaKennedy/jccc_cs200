/*
 * @author Josh Kennedy
 * @file holidays.cpp
 * Finds a holiday for a specified date from a list of holidays.
 */

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DATES = 60; // Max number of holidays in list
const int MAX_NAME_LEN = 81; // Max length of holiday name

// Definition of DayData type
struct DayData
{
	int month; // Month of Holiday
    int day; // Day of Holiday
	char holiday[MAX_NAME_LEN]; // Name of holiday
};

// Function prototype
bool findHoliday (const DayData holidayList[], int listLength, int month, int day, char*& holidayCopy);

int main ()
{
	DayData holidayList[MAX_DATES]; // List of holidays
	int count = 0; // Number of holidays in list
    int month = 0; // Input month
    int day = 0; // Input day
	char* holidayName = new char[MAX_NAME_LEN]; // Name of selected holiday
    
	// Open the designated file for input.
	ifstream holidayFile("/Users/joshuakennedy/Documents/Projects/CS 200/holidays/holidays/holidays.txt");
	if (holidayFile.fail())
	{
        cerr << "Can NOT open input file holidays.txt" << endl;
        exit(1);
	}
    
	// Read in the list of holidays.
	while (holidayFile.good() && (holidayFile >> holidayList[count].month >> holidayList[count].day))
	{
		holidayFile.get(); // Remove blank after day from the stream
		holidayFile.getline(holidayList[count].holiday, MAX_NAME_LEN, '\n'); // Read holiday name
		count++; // including spaces
	}
    
	// Close the file.
	holidayFile.close();
    
	// Prompt the user for the date of the desired hoilday.
	cout << endl << "Enter the month and day for a holiday: ";
	cin >> month >> day;
    
	// Display the holiday (if any) for the requested date.
	if (findHoliday(holidayList, count, month, day, holidayName))
        cout << holidayName << endl;
	else
        cout << "No holiday is listed" << endl;
    
    return 0;
}

//--------------------------------------------------------------------
// Insert your findHoliday() function here.
//--------------------------------------------------------------------
bool findHoliday (const DayData holidayList[], int listLength, int month, int day, char*& holidayCopy)
{
    for (int i = 0; i < listLength + 1; i++)
    {
        if (holidayList[i].month == month && holidayList[i].day == day)
        {
            // Sorry for the C-style cast! :)
            holidayCopy = (char*)holidayList[i].holiday;
            
            holidayCopy += '\0';
            
            return true;
        }
    }
    
    holidayCopy[0] = '\0';
    
    return false;
}

/* Output:
 
 Enter the month and day for a holiday: 1 11
 Hostos Day (Puerto Rico)
 Program ended with exit code: 0
 
 Enter the month and day for a holiday: 4 20
 No holiday is listed
 Program ended with exit code: 0
 
 */

