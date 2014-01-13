/*
 * project2.cpp - YEAH!! PROJECT 2!! :-)
 * Created by Josh Kennedy on 28 September 2013
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

enum CaloriesNeeded : unsigned short
{
	Metabolic = 0,
	Physical = 1,
	Digest = 2,
};

double caloriesNeeded(CaloriesNeeded, double, double, double);
double numberOfServings(double, double, double, double);

int main(int argc, char* argv[])
{
	double weight = 0.0;
	double intensity = 0.0;
	double minutes = 0.0;
	double calories = 0.0;

	cout << "Enter your weight in pounds: ";
	cin >> weight;

	cout << "\nCalories needed for metabolic: " << caloriesNeeded(CaloriesNeeded::Metabolic, weight, NULL, NULL) << "\n" << endl;

	cout << "Enter estimated intensity for physical activity: ";
	cin >> intensity;

	cout << "Enter time for physical activity in minutes: ";
	cin >> minutes;

	cout << "\nCalories needed for physical activity: " << caloriesNeeded(CaloriesNeeded::Physical, weight, intensity, minutes) << "\n" << endl;

	cout << "Enter amount of calories for one serving of your favorite food: ";
	cin >> calories;

	cout << "\nNumber of servings of food to maintain weight: " << numberOfServings(calories, weight, intensity, minutes) << "\n" << endl;

	system("PAUSE");

	return 0;
}

double caloriesNeeded(CaloriesNeeded type, double pounds, double intensity, double minutes)
{
	switch(type)
	{
	case CaloriesNeeded::Metabolic:
		return 70 * pow((pounds / 2.2), 0.756);
		break;
	case CaloriesNeeded::Physical:
		return 0.0175 * intensity * (pounds / 2.2) * minutes;
		break;
	case CaloriesNeeded::Digest:
		return (caloriesNeeded(CaloriesNeeded::Metabolic, pounds, NULL, NULL) + caloriesNeeded(CaloriesNeeded::Physical, pounds, intensity, minutes)) / 0.9;
		break;
	}
}

double numberOfServings(double foodCalories, double pounds, double intensity, double minutes)
{
	return caloriesNeeded(CaloriesNeeded::Digest, pounds, intensity, minutes) / foodCalories;
}

/* Test Case:

Enter your weight in pounds: 180

Calories needed for metabolic: 1955.3

Enter estimated intensity for physical activity: 15
Enter time for physical activity in minutes: 30

Calories needed for physical activity: 644.318

Enter amount of calories for one serving of your favorite food: 500

Number of servings of food to maintain weight: 5.77692

Press any key to continue . . .

*/
