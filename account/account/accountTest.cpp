/*
 * @author Josh Kennedy
 * @file accountTest.cpp
 * @description Create and manipulate Account objects.
 */

#include <iostream>

using namespace std;

// include definition of class Account from Account.h
#include "account.h"

// function main begins program execution
int main()
{
	Account account1(50.0); // create Account object
	Account account2(0.0); // create Account object
    
	// display initial balance of each object
	cout << "account1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;
    
	double withdrawalAmount; // stores withdrawal amount read from user
    
	cout << "\nEnter withdrawal amount for account1: "; // prompt
	cin >> withdrawalAmount; // obtain user input
	cout << "\nsubtracting " << withdrawalAmount << " from account1 balance\n\n";
	
    account1.debit(withdrawalAmount);
    
	// display balances
	cout << "account1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;
    
	cout << "\nEnter withdrawal amount for account2: "; // prompt
	cin >> withdrawalAmount; // obtain user input
	cout << "\nsubtracting " << withdrawalAmount << " from account2 balance\n\n";
	
    account2.debit(withdrawalAmount);
    
	// display balances
	cout << "account1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;
	return 0; // indicate successful termination
    
} // end main

/* output:
 
 account1 balance: $50
 account2 balance: $0
 
 Enter withdrawal amount for account1: 25
 
 subtracting 25 from account1 balance
 
 account1 balance: $25
 account2 balance: $0
 
 Enter withdrawal amount for account2: 69
 
 subtracting 69 from account2 balance
 
 insufficent funds!
 account1 balance: $25
 account2 balance: $-69
 Program ended with exit code: 0
 
 */

