/*
 * @author Josh Kennedy
 * @file extraCredit2.cpp
 *
 * Extra Credit Numero Dos
 *
 * Defines and tests class CounterType, which is used to count things.
 * CounterType contains both a default constructor and a constructor that
 * sets the count to a specified value, plus methods to increment, decrement,
 * return, and output the count.  The count is always nonnegative.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class CounterType
{
public:
    CounterType();
    //Initializes the count to 0.
    
    CounterType(int initCount);
    //Precondition: initCount holds the initial value for the count.
    //Postcondition:
    //  If initCount > 0,initializes the count to initCount.
    //  If initCount <= 0,initializes the count to 0.
    
    void increment();
    //Postcondition:
    //  The count is one more than it was.
    
    void decrement();
    //Postcondition:
    //  If the count was positive, it is now one less than it was.
    //  If the count was 0, it is still 0
    
    int getCount();
    void output(ostream& outStream);
    //Precondition: outStream is ready to write to
    //Postcondition: count has been written to outStream
    
private:
    int count;
};

int main()
{
    int counterInitialValue = 69;
    CounterType counter = CounterType(counterInitialValue);
    
    cout << "CounterType instance has been created with initial value of " << counter.getCount() << endl;
    
    for (int i = counterInitialValue; i > -5; i--)
    {
        counter.output(cout);
        cout << endl;
        counter.decrement();
    }
    
    counter = CounterType();
    
    cout << "Recreated CounterType instance with initial value of " << counter.getCount() << endl;
    cout << "Decrementing CounterType instance 2 times..." << endl;
    
    counter.decrement();
    counter.decrement();
    
    cout << "CounterType instance has a value of " << counter.getCount() << endl;
    
    for (int i = 0; i < 8; i++)
    {
        counter.output(cout);
        cout << endl;
        counter.increment();
    }
    
	return 0;
}

CounterType::CounterType()
{
    count = 0;
}

CounterType::CounterType(int initCount)
{
    if (initCount >= 0)
        count = initCount;
    else
        count = 0;
}

void CounterType::increment()
{
    count++;
}

void CounterType::decrement()
{
    if (count > 0)
        count--;
}

int CounterType::getCount()
{
    return count;
}

void CounterType::output(ostream& outStream)
{
    outStream << count;
}

/* output:
 
 CounterType instance has been created with initial value of 69
 69
 68
 67
 66
 65
 64
 63
 62
 61
 60
 59
 58
 57
 56
 55
 54
 53
 52
 51
 50
 49
 48
 47
 46
 45
 44
 43
 42
 41
 40
 39
 38
 37
 36
 35
 34
 33
 32
 31
 30
 29
 28
 27
 26
 25
 24
 23
 22
 21
 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 0
 0
 0
 0
 0
 Recreated CounterType instance with initial value of 0
 Decrementing CounterType instance 2 times...
 CounterType instance has a value of 0
 0
 1
 2
 3
 4
 5
 6
 7
 Program ended with exit code: 0
 
 */

