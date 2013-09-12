/**
* @author Josh Kennedy
* @date 31 August 2013
* @file eggGame.cpp
*/

#include <iostream>

using namespace::std;

//    Use of a flag to control the game
//    The program plays the role of the "Judge" for the game
//    -  program asks for a valid selection
//    -  program determines if the game is over
//    -  program declares the winner (last one to take eggs)

int main(int argc, char* argv[])
{
	bool gameOver = false; // flag
	int  numberEggs = 13;
	int  player = 1; // 1 for Tortoise, 2 for Hare
	int  selected;

	while(!gameOver)
	{
		cout << "Number of eggs remaining is " << numberEggs << endl;
		cout << "Enter your selection (1, 2 or 3) " 
			<< (player==1 ? "Tortoise" : "Hare") << " ";
		cin >> selected;
		
		// If move is legal: 1 to 3 eggs and no more than numberEggs remaining
		if (selected >= 1 && selected <= 3 && selected <= numberEggs)
		{    
			// adjust numberEggs
			numberEggs -= selected;

			if (numberEggs > 0)
			{
				// change players
				(player ? (player == 1 ? player = 2 : player = 1) : player = 1);
			}
			else
			{
				gameOver = true;
			}
		}
		else // not a valid selection
		{
			cout <<"Not a valid egg selection, try again\n";
		}
	 } // end while

	// declare the winner  (Tortoise or Hare)
	cout << "A winner is teh " << (player==1 ? "Tortoise" : "Hare") << endl;

	return 0;
} // end main

/* Test cases:

Number of eggs remaining is 13
Enter your selection (1, 2 or 3) Tortoise 1
Number of eggs remaining is 12
Enter your selection (1, 2 or 3) Hare 2
Number of eggs remaining is 10
Enter your selection (1, 2 or 3) Tortoise 2
Number of eggs remaining is 8
Enter your selection (1, 2 or 3) Hare 1
Number of eggs remaining is 7
Enter your selection (1, 2 or 3) Tortoise 3
Number of eggs remaining is 4
Enter your selection (1, 2 or 3) Hare 3
Number of eggs remaining is 1
Enter your selection (1, 2 or 3) Tortoise 1
A winner is teh Tortoise
Press any key to continue . . .

Number of eggs remaining is 13
Enter your selection (1, 2 or 3) Tortoise 2
Number of eggs remaining is 11
Enter your selection (1, 2 or 3) Hare 2
Number of eggs remaining is 9
Enter your selection (1, 2 or 3) Tortoise 1
Number of eggs remaining is 8
Enter your selection (1, 2 or 3) Hare 3
Number of eggs remaining is 5
Enter your selection (1, 2 or 3) Tortoise 2
Number of eggs remaining is 3
Enter your selection (1, 2 or 3) Hare 3
A winner is teh Hare
Press any key to continue . . .

Number of eggs remaining is 13
Enter your selection (1, 2 or 3) Tortoise 2
Number of eggs remaining is 11
Enter your selection (1, 2 or 3) Hare 2
Number of eggs remaining is 9
Enter your selection (1, 2 or 3) Tortoise 5
Not a valid egg selection, try again
Number of eggs remaining is 9
Enter your selection (1, 2 or 3) Tortoise 3
Number of eggs remaining is 6
Enter your selection (1, 2 or 3) Hare 2
Number of eggs remaining is 4
Enter your selection (1, 2 or 3) Tortoise 3
Number of eggs remaining is 1
Enter your selection (1, 2 or 3) Hare 2
Not a valid egg selection, try again
Number of eggs remaining is 1
Enter your selection (1, 2 or 3) Hare 1
A winner is teh Hare
Press any key to continue . . .

*/
