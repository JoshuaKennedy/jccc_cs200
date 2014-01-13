// account.h
// Definition of Account class.

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account
{
public:
	Account(double); // constructor initializes balance
    
	void credit(double); // add an amount to the account balance
    
    void debit(double); // subtract an amount from the account balance
    
	double getBalance(); // return the account balance
    
private:
    
	double balance; // data member that stores the balance
}; // end class Account

#endif
