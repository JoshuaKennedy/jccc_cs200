/*
 * Hurricane.cpp - Determines category of hurricane based on wind speed in mph.
 * Created by Josh Kennedy on 25 August 2013.
 */

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// Variable declaration and initialization.
	int speed = 0, category = -1;

	// Prompt user for input.
	cout << "Enter wind speed in mph: ";

	// Get input from user.
	cin >> speed;

	// Check the speeds to see if it falls under a category
	if (speed >= 65 && speed <= 85)
	{
		category = 0;
	}
	else if (speed >= 86 && speed <= 110)
	{
		category = 1;
	}
	else if (speed >= 111 && speed <= 135)
	{
		category = 2;
	}
	else if (speed >= 136 && speed <= 165)
	{
		category = 3;
	}
	else if (speed >= 166 && speed <= 200)
	{
		category = 4;
	}
	else if (speed > 200)
	{
		category = 5;
	}
	else
	{
		category = -1;
	}

	// Tell the user the result of the calculation.
	if (category != -1)
		cout << "The wind speed you entered, " << speed << " mph, is a category " << category << " hurricane." << endl;
	else
		cout << "The wind speed you entered, " << speed << " mph, is not a hurricane." << endl;

	// Signal to OS that program ended successfully.
	return 0;
}
