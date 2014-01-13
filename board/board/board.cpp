//
//  board.cpp
//
//  Created by Josh Kennedy on 11/1/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>

using namespace::std;

// Board dimensions
const int NUM_ROWS = 10;
const int NUM_COLS = 20;

// Function prototypes
void fillRectangle(char board[NUM_ROWS][NUM_COLS], int row, int col, int width, int height, char fillChar);

void displayBoard(const char board[NUM_ROWS][NUM_COLS]);

//--------------------------------------------------------------------

int main()
{
	char board[NUM_ROWS][NUM_COLS];   // Message board
    
	// Initialize the message board to all periods.
	fillRectangle(board, 0, 0, NUM_COLS, NUM_ROWS, '.');
    
	//  Load and display a message.
    fillRectangle(board, 2, 2, 6, 2, 'C'); // top of C
	fillRectangle(board, 4, 2, 3, 4, 'C'); // left side of C
	fillRectangle(board, 6, 5, 3, 2, 'C'); // bottom of C
	fillRectangle(board, 4, 10, 3, 1, '+'); // horizontal bar of first plus
	fillRectangle(board, 3, 11, 1, 3, '+'); // vertical bar of first plus
	fillRectangle(board, 3, 16, 1, 3, '+'); // vertical bar of second plus
	fillRectangle(board, 4, 15, 3, 1, '+'); // horizontal bar of second plus
    
	cout << endl;
	displayBoard(board);
    
	return 0;
}

void fillRectangle(char board[NUM_ROWS][NUM_COLS], int row, int col, int width, int height, char fillChar)
{
	// Fills in the specified rectangle on the message board
	// with the character fillChar.
    
    for (int i = col; i < width + col; i++)
    {
        for (int j = row; j < height + row; j++)
        {
            board[j][i] = fillChar;
        }
    }
}

//--------------------------------------------------------------------

void displayBoard(const char board[NUM_ROWS][NUM_COLS])
{
	// Displays the message board.
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            cout << board[i][j];
        }
        
        cout << endl;
    }
}

/*
 
 ....................
 ....................
 ..CCCCCC............
 ..CCCCCC...+....+...
 ..CCC.....+++..+++..
 ..CCC......+....+...
 ..CCCCCC............
 ..CCCCCC............
 ....................
 ....................
 Program ended with exit code: 0
 */

