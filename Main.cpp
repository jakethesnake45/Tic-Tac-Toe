#include <iostream>
#include <string>
using namespace std; 

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);


int main()
{
	
	runGame();
	
	return 0;
}
//end main

//-----| The game loop -runGame|------//
void runGame()
{
	string winner = "";
	bool xturn = true; // start with X's turn
	int theRow = 0;
	int theCol = 0;
	string gameBoard[ROWS][COLS];
	initializeGameBoard(gameBoard);

	// initial print 
	printCurrentBoard(gameBoard);

	while (winner == "")
	{

		if (xturn)
		{
			cout << "It is X's turn" << endl;
		}
		else
		{
			cout << "It is O's turn" << endl;
		}
		getUserInput(xturn, gameBoard);
		cout << endl; //extra spacing
		printCurrentBoard(gameBoard); // reprint the board
		winner = getWinner(gameBoard); // check for a winner
		xturn = !xturn; // flip it

		if (winner == "" && isBoardFull(gameBoard))
		{
			winner = "C"; // Cat's game... no winner!
		}
	} // end while

	cout << endl; //extra space before
	
	if (winner == "C")
	{
		cout << "It was a Cat's game! NO Winner!" << endl;
	}
	else
	{
		cout << "The winner is " << winner << endl; //print's X or O
	}
}      
//--------| initialize the Board---//
void initializeGameBoard(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = " "; // empty space
		}

	}
} // end initialize game board

//-----|print current board---//
void printCurrentBoard(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << gameBoard[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
	
		}
		cout << endl; 
		if (i < 2) 
		{
			cout << "- - - - -" << endl;
		}
	
	
	
	}
	cout << endl; //extra space

} // end print the current board

//--------| User input---------//
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
	int row = -1;
	int col = -1;
	bool keepAsking = true;
	while (keepAsking)
	{
		//keep asking until you get a vaild answer 
		cout << "Please enter the row then column, each from 0, 1, or 2, separated by a space" << endl;
		cin >> row;
		cin >> col;
		if (row >= 0 && col >= 0 && row <= 2 && col <= 2)
		{
			// vaild/in-range selection 
			// but it still could be occupited by X or O already..
			if (!cellAlreadyOccupied(row, col, gameBoard))
			{
				// only set the cell if the row/col vaild and not occupied 
				keepAsking = false;

			}
			else
			{
				cout << "That cell is already occupied!" << endl;
			}





		}

	} // end while
	
	if (xTurn) // must be an X 
	{
		gameBoard[row][col] = "X";
	}
	else // must be an O
	{
		gameBoard[row][col] = "O";
	}

} // end of user input

  // test if the cell is already occupied//
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
	return gameBoard[row][col] != " "; //if no space, then it's occupied
} // end cellAlreadyOccupied

// test if cell is already occupied// 
string getWinner(string gameBoard[ROWS][COLS])
{
	// check rows
	for (int i = 0; i < ROWS; i++)
	{
		if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
		{
			return gameBoard[i][0];
		}
	} // end for

	for (int i = 0; i < COLS; i++)
	{
		if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
		{
			return gameBoard[0][i]; //we have a match
		}
	}
	if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
	{
		return gameBoard[0][0];


	}
	if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
	{
		return gameBoard[2][0];

	}
	return ""; // no winner yet!

}




// test if the board is full 
bool isBoardFull(string gameBoard[ROWS][COLS])
{
	int countfull = 0;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] != " ")
			{
				countfull++;
			}


		}

	}
   return countfull == 9; // all 9 cells are full

} // end of board is full
