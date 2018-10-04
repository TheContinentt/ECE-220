/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

//Comment: This function counts the number of live neighbor for the input location of the cell.
//I use several if-else statement here to discuss the cell ar the corner, on the four sides
//and inner of the board respectively. And I use variable counter as a counter. In the end
//I return the counter value to the main function.
#include <stdlib.h>

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
	int counter = 0;
	if (row == 0 && col == 0)//This is the case that the cell is on the upperleft corner.
	{
		if (board[1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (row == boardRowSize-1 && col == boardColSize-1)//This is the case that the cell is on the lowerright corner.
	{
		if (board[(row+1)*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (row == boardRowSize-1 && col == 0)//This is the case that the cell is on the lowerleft corner.
	{
		if (board[(row-1)*boardColSize] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row-1)*boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (row == 0 && col == boardColSize-1)//This is the case that the cell is on the upperright corner.
	{
		if (board[col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[2*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
		if (board[2*boardColSize-1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (row == 0 && (col != 0 && col != boardColSize-1))//This is the case that the cell is on the upper side of board except two corners on it.
	{
		if (board[col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[col+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize+col] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize+col+1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (row == boardRowSize-1 && (col != 0 && col != boardColSize-1))//This is the case that the cell is on the lower side of board except two corners on it.
	{
		if (board[boardColSize*row+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize*row+col+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize*(row-1)+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize*(row-1)+col] == 1)
		{
			counter = counter + 1;
		}
		if (board[boardColSize*(row-1)+col+1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (col ==  0 && (row != 0 && row != boardRowSize-1))//This is the case that the cell is on the left side of board except two corners on it.
	{
		if (board[row*boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row-1)*boardColSize] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row-1)*boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize+1] == 1)
		{
			counter = counter + 1;
		}
	}
	else if (col ==  boardColSize-1 && (row != 0 && row !=boardRowSize-1))//This is the case that the cell is on the right side of board except two corners on it.
	{
		if (board[row*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+2)*boardColSize-2] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+2)*boardColSize-1] == 1)
		{
			counter = counter + 1;
		}
	}
	else//This is the case that the cell is located in the inner of the board.
	{
		if (board[(row-1)*boardColSize+col] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row-1)*boardColSize+col+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row-1)*boardColSize+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[row*boardColSize+col+1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize+col-1] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize+col] == 1)
		{
			counter = counter + 1;
		}
		if (board[(row+1)*boardColSize+col+1] == 1)
		{
			counter = counter + 1;
		}
	}

	return counter;//This is the return value of this countLiveNeighbor function, which represents the live neighbor numbers of the specific cell.

}
/*
 * Update the game board to the next step.
 * Input:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */

//Comment: This function automatically update the board after one generation. It first computes the neighbor live numbers by function countLiveNeighbor.
//Then determine for the generation wwhether it's alive or not by specific rules and if=else statement. But the result is first restored ina temporary
//array. And after one step is finished, I upload the temporary array to the board array, which means that the board is update for one generation.

void updateBoard(int* board, int boardRowSize, int boardColSize) {
	int ii,jj;
	int status;
	int* temp = malloc(boardRowSize*boardColSize*sizeof(int));
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			status = countLiveNeighbor(board, boardRowSize, boardColSize, ii, jj);//Here status is the live neighbor of the specific cell
			if (board[ii * boardColSize + jj] == 1)//If this cell is alive, and has 2 or 3 live neighbor, it's still alive in the next generation.
			{
				if (status == 2 || status == 3)
				{
					temp[ii * boardColSize + jj] = 1;
				}
				else if (status < 2 || status > 3)//Else it becomes dead.
				{
					temp[ii * boardColSize + jj] = 0;
				}
			}
			else if (board[ii * boardColSize + jj] == 0)//If it's dead in this generation.
			{
				if (status == 3)//And has a live neighbor of exactly 3, it'll be alive in the next generation.
				{
					temp[ii * boardColSize + jj] = 1;
				}
				else//Else it's still dead.
				{
					temp[ii * boardColSize + jj] = 0;
				}
			}
		}
	}
	for (ii = 0; ii < boardRowSize; ii++)//This loop just copy the value in temporary array to the exact board array.
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			board[ii * boardColSize + jj] = temp[ii * boardColSize + jj];
		}
	}







}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */


//Comment: This function compares the reult of current generation to the last generation to determine whether there's no change between
//these two generations. I fthere's indeed no change happens, the game ends. Also if all the number in the board array is 0,
//the game also ends. I copy several part of my code in the updateBoard function to make this aliveStable function more clear and efficient.


int aliveStable(int* board, int boardRowSize, int boardColSize){
	int count = 0;
	int countt = 0;
	int ii,jj;
	int kk;
	int status;
	int* temp = malloc(boardRowSize*boardColSize*sizeof(int));
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			status = countLiveNeighbor(board, boardRowSize, boardColSize, ii, jj);//count the live neighbor this cell.
			if (board[ii * boardColSize + jj] == 1)
			{
				countt = countt + 1;//if the number in this location is 1, then increment the count for live cells.
				if (status == 2 || status == 3)
				{
					temp[ii * boardColSize + jj] = 1;
				}
				else if (status < 2 || status > 3)
				{
					temp[ii * boardColSize + jj] = 0;
				}
			}
			else if (board[ii * boardColSize + jj] == 0)
			{
				if (status == 3)
				{
					temp[ii * boardColSize + jj] = 1;
				}
				else
				{
					temp[ii * boardColSize + jj] = 0;
				}
			}
		}
	}
	for (kk = 0; kk < boardRowSize*boardColSize; kk++)
	{
			if (board[kk] != temp[kk])//this for loop counts the number that change between two generations.
			{
				count = count + 1;
			}
	}

	if (count == 0 || countt == 0)//If there's no change or no live cells any more, the game ends and the return value is 1.
	{
		return 1;
	}

	return 0;//Else the game continues and return value is 0.


}
