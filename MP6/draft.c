void updateBoard(int* board, int boardRowSize, int boardColSize) {
	int row,col;
	int status;
	int order;
	int orderr;
	int* temp = malloc(boardRowSize*boardColSize*sizeof(int));
	for (row = 0; row < boardRowSize; row++)
	{
		for (col = 0; col < boardColSize; col++)
		{
			order = row * boardColSize + col;
			status = countLiveNeighbor(board, boardRowSize, boardColSize, row, col);
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
	for (row = 0; row < boardRowSize; row++)
	{
		for (col = 0; col < boardColSize; col++)
		{
			orderr = row * boardColSize + col;
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
	int kk,mm;
	int* next = malloc(boardRowSize*boardColSize*sizeof(int));
	for (kk = 0; kk <= boardRowSize*boardColSize-1; kk++)
	{
		next[kk] = board[kk];
	}
	updateBoard(board, boardRowSize, boardColSize);
	for (mm = 0; mm <= boardRowSize*boardColSize-1; mm++)
	{
		if (next[mm] == board[mm])
		{
			count = count + 1;
		}
	}
	if (count == boardRowSize*boardColSize)
	{
		return 1;
	}

	return 0;


}

				
				
