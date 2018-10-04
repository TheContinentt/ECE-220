/*The following programs accounts for the core instruction of game "game of life." The first function countLiveNeighbor would count all the "1"s at a given point in the one-dimension
array. To cancel overcounting, the return value would substract one if the given point is a "1". The second function would compute the next stage status given the number of "1"s at
given location counted by using the first function. Then by using the third function, the game board would be updated to the newest version.
*/


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
            int index;
            int m,n,increment;
            int row_end_condition;
            int col_end_condition;
            int count=0;

            if(row==0){ //if tested is at the first row, neighbors only contains that and the next row.
              m=row;
              row_end_condition=row+1;//the test condition would terminates at the next row
            }

            if(row!=0&&row<boardRowSize){
              m=row-1;//if not at the first row, has neighbors at row-1,row, and row+1
              row_end_condition=row+1;
              if(row==boardRowSize-1){//if at the last row, neighbors only at row-1,row
                row_end_condition=row;
              }
            }

            if(col==0){//if at first col, neighbors only at col,col+1
              n=col;
              col_end_condition=2;
            }

            if(col!=0&&col<boardColSize){
              n=col-1;//if not at first col, nieghbors at col-1,col,col+1
              col_end_condition=3;
              if(col==boardColSize-1)//if at the last col, neighbors only at col-1,col
                col_end_condition=2;
              }

            for (increment=0;increment<col_end_condition;increment++){
                    index=(m)*boardColSize+(n);//locate the first cell to test, and the sebsequent cell by adding increment
                    if(board[index+increment]==1){
                      count=count+1;
                    }

                    if(increment==col_end_condition-1&&m!=row_end_condition){
                    increment=-1;//if finished testing the first row, update increment to 0 by setting increment to -1 for the special structure of for looop
                    m=m+1;
                    }

            }
            if(board[row*boardColSize+col]==1){//if the central cell tested contains 1, substract the total count by 1 for overcounting
              count=count-1;
            }
            if(count==-1){//if only the central cell is one, and overcounting is taken into account avoidablely, reset count to cancel this negative affect
              count=0;
            }
return count;
}
/*
 * Update the game board to the next step.u may find debugging frustrating (many of us do). A useful tool is gdb (http://www.gnu.org/software/gdb/), introduced in lab last week. You can use this tool to set breakpoints, step through your code and print values.
You can start gdb using
 * Input:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
      int row,col;
      int* tem_storage = malloc(boardRowSize*boardColSize*sizeof(int));//set another array for tempoary storage of status in game board
      int status_index;
      int num_counts;
      for(row=0;row<boardRowSize;row++){
          for(col=0;col<boardColSize;col++){
            status_index=row*boardColSize+col;
            num_counts=countLiveNeighbor(board,boardRowSize,boardColSize,row,col);

              if(board[status_index]==1){
                  if(num_counts<2||num_counts>3){//live cell would die if neighbors has less than 2 or more than 3 alive
                    tem_storage[status_index]=0;
                  }

                  else if(num_counts==3||num_counts==2){
                    tem_storage[status_index]=1;//live cell would continue to live if neighbors has 2 or 3 alives
                  }
              }

              else if(board[status_index]==0){
                  if(num_counts==3){//dead cell would relive if exactly 3 lives neighbors found
                    tem_storage[status_index]=1;
                  }
                  else{
                    tem_storage[status_index]=0;
                  }
            }

          }
      }

      for(row=0;row<boardRowSize;row++){
          for(col=0;col<boardColSize;col++){
            status_index=row*boardColSize+col;
            board[status_index]=tem_storage[status_index];//update the game_board to the latest version.
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
  int row,col;
  int status_index;
  int counter=0;
  int tem_storage_check [boardRowSize*boardColSize*sizeof(int)];
  int num_counts;
  int one_counts=0;
  for(row=0;row<boardRowSize;row++){//simply copying codes from updateBoard function
      for(col=0;col<boardColSize;col++){
        status_index=row*boardColSize+col;
        num_counts=countLiveNeighbor(board,boardRowSize,boardColSize,row,col);

          if(board[status_index]==1){
              one_counts++;//if one found, than increase counter
              if(num_counts<2||num_counts>3){
                tem_storage_check[status_index]=0;
              }

              else if(num_counts==3||num_counts==2){
                tem_storage_check[status_index]=1;
              }
          }

          else if(board[status_index]==0){
              if(num_counts==3){
                tem_storage_check[status_index]=1;
              }
              else{
                tem_storage_check[status_index]=0;
              }
          }

      }
  }

  for(row=0;row<boardRowSize;row++){
      for(col=0;col<boardColSize;col++){
        status_index=row*boardColSize+col;
        if(board[status_index]!=tem_storage_check[status_index]){
          counter++;//if disagreement between the current board and the next version of board is found, increment counter
        }
      }
  }


  if (counter==0||one_counts==0){//if all zero or the current version of board is the same as the next version, return 1, otherwise return 0
	return 1;
  }
  return 0;
}
