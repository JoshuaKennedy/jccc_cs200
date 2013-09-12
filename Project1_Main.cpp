/*
 * Project1_Main.cpp - Main entry point for Project 1
 * Created by Josh Kennedy on 6 September 2013
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Typically, I would declare the classes in their own separate header, and then implement them in a separate source file, but I didn't. :)

// Lap class contains lap time attribute.
class Lap
{
public:
	double lapTime; // Lap time.
};

// Racer class contains id, raceTime attrbutes, along with a std::vector to store individual Lap objects.
class Racer
{
public: 
	std::string id; // The racer's id
	double raceTime; // Racer's total time.
	std::vector<Lap> laps; // Lap object vector.

	// Constructor
	Racer(std::string myId, double totalRaceTime, int numberOfLaps, std::vector<Lap> myLaps)
	{
		// Set attributes.
		this->id = myId;
		this->laps = myLaps;
		this->raceTime = totalRaceTime;
	}
};

// Application entry point.
int main (int argc, char* argv[])
{
	// Declare and initialize.
	std::vector<Racer*> racers; // Dereferenced Racer object vector.
	int numRacers = 0; // Number of total racers.
	int numLaps = 0; // Number of total laps.

	// Grab inputs.
	std::cout << "Enter number of racers: ";
	std::cin >> numRacers;

	std::cout << "Enter number of laps in each race: ";
	std::cin >> numLaps;

	std::cout << std::endl;

	// Iterate through each racer.
	for (int i = 0; i < numRacers; i++)
	{
		// Declare and initialize variables.
		std::string id;
		double raceTime = 0.0;
		std::vector<Lap> myLaps;
		double lapsSum = 0.0;

		// Grab inputs.
		std::cout << "Enter racer ID: ";
		std::cin >> id;

		std::cout << "Enter total race time: ";
		std::cin >> raceTime;

		// Iterate through each lap
		for (int laps = 0; laps < numLaps; laps++)
		{
			// Declare and initialize lapTime variable.
			double lapTime = 0.0;

			// Prompt and grab input.
			std::cout << "For Racer " << id << ", enter time for Lap " << (laps + 1) << ": ";
			std::cin >> lapTime;

			// Keep track of the sum of the laps.
			lapsSum += lapTime;

			// Instantiate Lap object.
			Lap myLap;
			myLap.lapTime = lapTime;

			// Push Lap object to the back of the laps vector.
			myLaps.push_back(myLap);
		}

		// Instantiate dereferenced Racer object and push it to the back of the racers vector.
		Racer* racer = new Racer(id, raceTime, numLaps, myLaps);
		racers.push_back(racer);

		// If the sum of the laps is equal to the total race time...
		if (lapsSum == raceTime)
		{
			// ...then both timekeepers agree!
			std::cout << "Both timekeepers agree with the time." << std::endl;
		}
		else
		{
			// Otherwise, they don't agree.
			double difference = std::abs((lapsSum - raceTime)); // We take the absolute value of the difference so it doesn't look weird.
			std::cout << "Judges differ by " << difference << std::endl;
		}

		// Separate the racers.
		std::cout << std::endl;
	}

	// So we can keep track of the fastest time.
	double fastestTime = racers.at(0)->raceTime;
	std::string fastestRacer;
	std::vector<Racer*>::iterator itr;

	// Iterate through the racers vector
	for (itr = racers.begin(); itr != racers.end(); ++itr)
	{
		// Create a dereferenced racer object local in scope to this current iteration of the loop.
		Racer* racer = *itr;

		// If the racer's total race time is greater than the current fastest time...
		if (racer->raceTime <= fastestTime)
		{
			// Assign the racer's total race time to the fastest time variable, and record which racer it is.
			fastestTime = racer->raceTime;
			fastestRacer = racer->id;
		}
	}

	// Declare the winner!
	std::cout << "A winner is, racer " << fastestRacer << ", with the time of " << fastestTime << std::endl;

	// Pause the console. (Only works on Windows)
	system("PAUSE");

	// Program success!
	return 0;
}

/* Example output:

Enter number of racers: 4
Enter number of laps in each race: 2

Enter racer ID: 111
Enter total race time: 120
For Racer 111, enter time for Lap 1: 60
For Racer 111, enter time for Lap 2: 61
Judges differ by 1

Enter racer ID: 222
Enter total race time: 118
For Racer 222, enter time for Lap 1: 60
For Racer 222, enter time for Lap 2: 58
Both timekeepers agree with the time.

Enter racer ID: 333
Enter total race time: 121
For Racer 333, enter time for Lap 1: 59
For Racer 333, enter time for Lap 2: 65
Judges differ by 3

Enter racer ID: 444
Enter total race time: 119
For Racer 444, enter time for Lap 1: 57
For Racer 444, enter time for Lap 2: 62
Both timekeepers agree with the time.

A winner is, racer 222, with the time of 118
Press any key to continue . . .

*/