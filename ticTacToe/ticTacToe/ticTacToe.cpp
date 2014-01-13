//
//  ticTacToe.cpp
//
//  Created by Josh Kennedy on 10/27/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
using namespace std;

const int NUM_ROWS = 3;
const int NUM_COLS = 3;

void displayBoard(const char t[][NUM_COLS]);
bool isWinner(const char t[][NUM_COLS], char);

int main()
{
	// declare variables
	char t[NUM_ROWS][NUM_COLS];
	char player = 'X';	// player is 'X','O', or 'T' ('T' is a tie game)
	int numberTurns; // maximum number of turns
	bool gameOver = false;
	int row;	// player's row choice, should be between 1 and 3
	int col;	// player's col choice, should be between 1 and 3
	int i;
	int j;
    
	// initialize variables
	numberTurns = NUM_ROWS * NUM_COLS;
    
	for (i = 0; i < NUM_ROWS; i++)
    {
		for (j = 0; j < NUM_COLS; j++)
        {
			t[i][j] = ' ';
        }
    }
    
	// loop while game is not over
	while(!gameOver)
	{
		// display the board and get player's move
		displayBoard(t);
		cout << "Enter your move (row and col), player " << player << ": ";
		cin >> row >> col;
        
		// check for valid row and column and spot had not already been taken
		while (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS)
		{
			cout << "Invalid row and col -- each must be between 1 and 3 \n";
			cout << "Enter your move (row and col), player " << player << ": ";
			cin >> row >> col;
		}
        
		// check that spot has not already been taken
		while (t[row-1][col-1] != ' ')
		{
			cout << "That row and col already taken \n";
			cout << "Enter your move (row and col), player " << player << ": ";
			cin >> row >> col;
		}
        
		// move is valid, mark it and decrement number of turns
		t[row-1][col-1] = player;
		numberTurns--;
        
		// check for a winner
		if(isWinner(t, player))
			gameOver = true;
		else if (numberTurns==0)
		{
			// no more moves available
			gameOver = true;
			player = 'T';
		}
		else
		{
			// game is not over, switch players
			if(player=='X')
				player='O';
			else
				player='X';
		}
	}
    
	// game is over, display the board and declare the winner
	displayBoard(t);
	if (player == 'X')
		cout << "          X's win!" << endl;
	else if (player == 'O')
		cout << "          O's win!" << endl;
	else
		cout << "          It's a tie!" << endl;
    
	return 0;
} // end main

void displayBoard(const char t[][NUM_COLS])
{
	int i, j, k;
	for(i = 0; i < NUM_ROWS; i++)
    {
		for(j = 0; j < NUM_COLS; j++)
        {
			if(j != NUM_COLS -1)
				cout << t[i][j] << '|';
			else
			{
				cout << t[i][j] << endl;
                
				if(i != NUM_ROWS-1)
                {
					for(k = 0; k < NUM_COLS; k++)
                    {
						if(k != NUM_COLS - 1)
							cout << "--";
						else
							cout << "-\n";
                    }
                }
			} // end of else
        }
    }
} // end displayBoard

bool isWinner(const char t[][NUM_COLS], char player)
{
	// there are NUM_ROWS + NUM_COLS + 2 (diagonals) ways to win
	// check each of them for a winner
	// NOTE:  you only have to check against the last player to
	//          make a move -- that player's mark is in the
	//          variable player
    
    bool result = false;
    
    // Check for horizontal wins.
    for (int i = 0; i < NUM_ROWS; i++)
    {
        result = true;
        
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (t[i][j] != player)
            {
                result = false;
                break;
            }
        }
        
        if (result)
            return true;
    }
    
    // Check for vertical wins.
    for (int i = 0; i < NUM_ROWS; i++)
    {
        result = true;
        
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (t[j][i] != player)
            {
                result = false;
                break;
            }
        }
        
        if (result)
            return true;
    }
    
    // Check for diagonal left-right win.
    for (int i = 0; i < NUM_COLS; i++)
    {
        result = true;
        
        if (t[i][i] != player)
        {
            result = false;
            break;
        }
    }
    
    if (result)
        return true;
    
    // Check for diagonal right-left win.
    for (int i = NUM_COLS - 1; i > 0; i--)
    {
        result = true;
        
        if (t[NUM_COLS - i - 1][i] != player)
        {
            result = false;
            break;
        }
    }
    
    return result;
} // end isWinner

/*

