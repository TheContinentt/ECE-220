#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

//Introduction: This program is to solve the input mazes. First  function is to create maze by dynamicaly allocating
//a 2D memory in heap. Then by using fopen and fscanf to read and print the maze in file to terminal. 
// Second function I use free to free the memory. In Print function, I use two for loops to print the elements in
// this 2D array. In the last function, I use the algorithm offered on the course wiki to solve the maze.

/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */

//Comment: IN this function, I first fopen the file and read the column and row numbers. Then I allocate memory
// for a 2D array which row and column are read in the file. Then I use fgetc to read characters one by one
// and store them in the heap. And I add two if statements to set start position and end position of maze_t.
// After we store the content of the maze_t, we return maze_t in the end.

maze_t * createMaze(char * fileName)
{
    // Your code here. Make sure to replace following line with your own code.
	FILE * file;
	int row, col;
	int i, j;
	char temp;	
	file = fopen(fileName, "r");	
		fscanf(file, "%d %d", &row, &col);
		maze_t * mymaze = (maze_t* )malloc(sizeof(maze_t));
		mymaze->width = col;
		mymaze->height = row;
		mymaze->cells = (char** )malloc(row*sizeof(char*));
		for (i = 0; i < row; i++)
		{
			mymaze->cells[i] = (char* )malloc(col*sizeof(char));
		}
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				temp = fgetc(file);
				if (temp == '\n')
				{
					mymaze->cells[i][j] = fgetc(file);
					if (mymaze->cells[i][j] == 'S')
					{
					mymaze->startColumn = j;
					mymaze->startRow = i;
					}
					if (mymaze->cells[i][j] == 'E')
					{
					mymaze->endColumn = j;
					mymaze->endRow = i;
					}
				}
				else 
				{
					mymaze->cells[i][j] = temp;
					if (temp == 'E')
					{
					mymaze->endColumn = j;
					mymaze->endRow = i;
					}
					if (temp == 'S')
					{
					mymaze->startColumn = j;
					mymaze->startRow = i;
					}
				}
				
			}
		}
		fclose(file);
		return mymaze;
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */

// Comment: SInce cells in maze is a 2D array. So I first use for loop to free each row first.
// Then free the double pointer and maze structure.

void destroyMaze(maze_t * maze)
{
	int i;
	for (i = 0; i < maze->height; i++)
	{
		free(maze->cells[i]);
	}
	free(maze->cells);
	free(maze);
    // Your code here.
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */

// Comment: In this function, I use two for loops to print the 2D array col by col
// and row by row. When the col_index reaches the end of the column, I use one
// if statement to print a newline character.
void printMaze(maze_t * maze)
{
	int height, width, i, j;
	height = maze->height;
	width = maze->width;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%c", maze->cells[i][j]);
			if (j == width - 1)
			{
				printf("\n");
			}
		}
	}
    // Your code here.
}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 

// Comment: In this function, I follow the algorithm offered on the course wiki. When I need to return true, return value is 1.
// Otherwise I return 0.
int solveMazeManhattanDFS(maze_t * maze, int col, int row)
{
    // Your code here. Make sure to replace following line with your own code.
	int h, w, er, ec;
	h = maze->height;
	w = maze->width;
	er = maze->endRow;
	ec = maze->endColumn;
	if (col > w - 1 || row > h - 1 || col < 0 || row < 0)
	{
		return 0;
	}
	if (maze->cells[row][col] == '.' || maze->cells[row][col] == '~' || maze->cells[row][col] == '%')
	{
		return 0;
	}
	if (er == row && ec == col)
	{
		return 1;
	}
	if (maze->cells[row][col] != 'S')
	{
		maze->cells[row][col] = '.';
	}
		if (solveMazeManhattanDFS(maze, col - 1, row) == 1)
		{
			return 1;
		}
		if (solveMazeManhattanDFS(maze, col + 1, row) == 1)
		{
			return 1;
		}
		if (solveMazeManhattanDFS(maze, col, row - 1) == 1)
		{
			return 1;
		}
		if (solveMazeManhattanDFS(maze, col, row + 1) == 1)
		{
			return 1;
		}
	if (maze->cells[row][col] != 'S')
	{
		maze->cells[row][col] = '~';
	}
		return 0;
}
