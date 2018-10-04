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
#include <stdlib.h>

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
	int counter = 0;
	if (row == 0 && col == 0)
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
	else if (row == boardRowSize-1 && col == boardColSize-1)
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
	else if (row == boardRowSize-1 && col == 0)
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
	else if (row == 0 && col == boardColSize-1)
	{
		if (board[col] == 1)
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
	else if (row == 0 && (col != 0 && col != boardColSize-1))
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
	else if (row == boardRowSize-1 && (col != 0 && col != boardColSize-1))
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
	else if (col ==  0 && (row != 0 && row != boardRowSize-1))
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
	else if (col ==  boardColSize-1 && (row != 0 && row !=boardRowSize-1))
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
	else
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

	return counter;

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
void updateBoard(int* board, int boardRowSize, int boardColSize) {
	int row,col;
	int status;
	int order;
	int orderr;
	int* temp = malloc(boardRowSize*boardColSize*sizeof(int));
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			order = ii * boardColSize + jj;
			status = countLiveNeighbor(board, boardRowSize, boardColSize, ii, jj);
			if (board[order] == 1)
			{
				if (status == 2 || status == 3)
				{
					temp[order] = 1;
				}
				else if (status < 2 || status > 3)
				{
					temp[order] = 0;
				}
			}
			else if (board[order] == 0)
			{
				if (status == 3)
				{
					temp[order] = 1;
				}
				else
				{
					temp[order] = 0;
				}
			}
		}
	}
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			orderr = ii * boardColSize + jj;
			board[orderr] = temp[orderr];
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
int aliveStable(int* board, int boardRowSize, int boardColSize){
	int count = 0;
	int countt = 0;
	int ii,jj;
	int order, orderr;
	int status;
	int* temp = malloc(boardRowSize*boardColSize*sizeof(int));
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			order = ii * boardColSize + jj;
			status = countLiveNeighbor(board, boardRowSize, boardColSize, ii, jj);
			if (board[order] == 1)
			{
				countt = countt + 1;
				if (status == 2 || status == 3)
				{
					temp[order] = 1;
				}
				else if (status < 2 || status > 3)
				{
					temp[order] = 0;
				}
			}
			else if (board[order] == 0)
			{
				if (status == 3)
				{
					temp[order] = 1;
				}
				else
				{
					temp[order] = 0;
				}
			}
		}
	}
	for (ii = 0; ii < boardRowSize; ii++)
	{
		for (jj = 0; jj < boardColSize; jj++)
		{
			orderr = ii * boardColSize + jj;
			if (board[orderr] != temp[orderr])
			{
				count = count + 1;
			}
		}
	}
	
	if (count == 0 || countt == 0)
	{
		return 1;
	}

	return 0;


}

				
				
