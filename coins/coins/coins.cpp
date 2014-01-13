/*
 * @author Josh Kennedy
 * @file coins.cpp 
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Coins class definition.
class Coins
{
public:
	// Constructors
	Coins(void);
	Coins(int q, int d, int n, int p);
    
	// Mutator Functions
	void setPennies(int);
	void setNickels(int);
	void setDimes(int);
	void setQuarters(int);
    
	// Accessor Functions
	int getPennies();
	int getNickels();
	int getDimes();
	int getQuarters();
    
	// Other Functions
	void advanceOnePenny();
    //  increase the pennies amount by 1
    //      NOTE:  you may have to advance the nickels
    //             you may have to advance the dimes
    //             you may have to advance the quarters
    //  in other words, minimize the number of coins
    
	void output(ostream&);
	void zeroOut(); // set quarters, dimes, nickels & pennies to 0
    
private:
    // Private Attributes
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};

// Entry point to application.
int main()
{
    // Instantiate new Coins object.
	Coins stackOfChange(0, 1, 1, 3);
    
    // Add 33 cents to the stackOfChange
	for( int i = 1; i <= 33; i++)
	{
		stackOfChange.advanceOnePenny();
		stackOfChange.output(cout);
	}
    
    // Reset
	stackOfChange.zeroOut();
	stackOfChange.output(cout);
    
	stackOfChange.setQuarters(3);
	stackOfChange.setDimes(1);
	stackOfChange.setNickels(1);
	stackOfChange.setPennies(2);
    
	cout << stackOfChange.getQuarters()  << ' ' << stackOfChange.getDimes() << ' ' << stackOfChange.getNickels() << ' ' << stackOfChange.getPennies() << endl;
    
	return 0;
}

// Coins Class - Constructor Implementations

Coins::Coins()
{
    this->zeroOut();
}

Coins::Coins(int q, int d, int n, int p)
{
    this->quarters = q;
    this->dimes = d;
    this->nickels = n;
    this->pennies = p;
}

// Coins Class - Mutator Function Implementations

void Coins::setPennies(int p)
{
    this->pennies = p;
}

void Coins::setNickels(int n)
{
    this->nickels = n;
}

void Coins::setDimes(int d)
{
    this->dimes = d;
}

void Coins::setQuarters(int q)
{
    this->quarters = q;
}

// Coins Class - Accessor Function Implementations

int Coins::getPennies()
{
    return this->pennies;
}

int Coins::getNickels()
{
    return this->nickels;
}

int Coins::getDimes()
{
    return this->dimes;
}

int Coins::getQuarters()
{
    return this->quarters;
}

// Coins Class - Other Function Implementations

void Coins::advanceOnePenny()
{
    this->pennies++;
    
    if (this->pennies >= 5)
    {
        this->pennies -= 5;
        
        this->nickels++;
    }
    
    if (this->nickels >= 2)
    {
        this->nickels -= 2;
        
        this->dimes++;
    }
    
    if (this->dimes >= 2 && this->nickels >= 1)
    {
        this->dimes -= 2;
        this->nickels -= 1;
        
        this->quarters++;
    }
}

void Coins::output(ostream& output)
{
    output << "Quarters: " << this->quarters << endl;
    output << "Dimes: " << this->dimes << endl;
    output << "Nickels: " << this->nickels << endl;
    output << "Pennies: " << this->pennies << endl;
    
    output << std::setprecision(2) << std::fixed << "Total Change: " << '$' << ((this->quarters * 0.25) + (this->dimes * 0.1) + (this->nickels * 0.05) + (this->pennies * 0.01)) << endl << endl;
}

void Coins::zeroOut()
{
    this->quarters = 0;
    this->dimes = 0;
    this->nickels = 0;
    this->pennies = 0;
}

/* Output:
 
 Quarters: 0
 Dimes: 1
 Nickels: 1
 Pennies: 4
 Total Change: $0.19
 
 Quarters: 0
 Dimes: 2
 Nickels: 0
 Pennies: 0
 Total Change: $0.20
 
 Quarters: 0
 Dimes: 2
 Nickels: 0
 Pennies: 1
 Total Change: $0.21
 
 Quarters: 0
 Dimes: 2
 Nickels: 0
 Pennies: 2
 Total Change: $0.22
 
 Quarters: 0
 Dimes: 2
 Nickels: 0
 Pennies: 3
 Total Change: $0.23
 
 Quarters: 0
 Dimes: 2
 Nickels: 0
 Pennies: 4
 Total Change: $0.24
 
 Quarters: 1
 Dimes: 0
 Nickels: 0
 Pennies: 0
 Total Change: $0.25
 
 Quarters: 1
 Dimes: 0
 Nickels: 0
 Pennies: 1
 Total Change: $0.26
 
 Quarters: 1
 Dimes: 0
 Nickels: 0
 Pennies: 2
 Total Change: $0.27
 
 Quarters: 1
 Dimes: 0
 Nickels: 0
 Pennies: 3
 Total Change: $0.28
 
 Quarters: 1
 Dimes: 0
 Nickels: 0
 Pennies: 4
 Total Change: $0.29
 
 Quarters: 1
 Dimes: 0
 Nickels: 1
 Pennies: 0
 Total Change: $0.30
 
 Quarters: 1
 Dimes: 0
 Nickels: 1
 Pennies: 1
 Total Change: $0.31
 
 Quarters: 1
 Dimes: 0
 Nickels: 1
 Pennies: 2
 Total Change: $0.32
 
 Quarters: 1
 Dimes: 0
 Nickels: 1
 Pennies: 3
 Total Change: $0.33
 
 Quarters: 1
 Dimes: 0
 Nickels: 1
 Pennies: 4
 Total Change: $0.34
 
 Quarters: 1
 Dimes: 1
 Nickels: 0
 Pennies: 0
 Total Change: $0.35
 
 Quarters: 1
 Dimes: 1
 Nickels: 0
 Pennies: 1
 Total Change: $0.36
 
 Quarters: 1
 Dimes: 1
 Nickels: 0
 Pennies: 2
 Total Change: $0.37
 
 Quarters: 1
 Dimes: 1
 Nickels: 0
 Pennies: 3
 Total Change: $0.38
 
 Quarters: 1
 Dimes: 1
 Nickels: 0
 Pennies: 4
 Total Change: $0.39
 
 Quarters: 1
 Dimes: 1
 Nickels: 1
 Pennies: 0
 Total Change: $0.40
 
 Quarters: 1
 Dimes: 1
 Nickels: 1
 Pennies: 1
 Total Change: $0.41
 
 Quarters: 1
 Dimes: 1
 Nickels: 1
 Pennies: 2
 Total Change: $0.42
 
 Quarters: 1
 Dimes: 1
 Nickels: 1
 Pennies: 3
 Total Change: $0.43
 
 Quarters: 1
 Dimes: 1
 Nickels: 1
 Pennies: 4
 Total Change: $0.44
 
 Quarters: 1
 Dimes: 2
 Nickels: 0
 Pennies: 0
 Total Change: $0.45
 
 Quarters: 1
 Dimes: 2
 Nickels: 0
 Pennies: 1
 Total Change: $0.46
 
 Quarters: 1
 Dimes: 2
 Nickels: 0
 Pennies: 2
 Total Change: $0.47
 
 Quarters: 1
 Dimes: 2
 Nickels: 0
 Pennies: 3
 Total Change: $0.48
 
 Quarters: 1
 Dimes: 2
 Nickels: 0
 Pennies: 4
 Total Change: $0.49
 
 Quarters: 2
 Dimes: 0
 Nickels: 0
 Pennies: 0
 Total Change: $0.50
 
 Quarters: 2
 Dimes: 0
 Nickels: 0
 Pennies: 1
 Total Change: $0.51
 
 Quarters: 0
 Dimes: 0
 Nickels: 0
 Pennies: 0
 Total Change: $0.00
 
 3 1 1 2
 Program ended with exit code: 0
 
 */

