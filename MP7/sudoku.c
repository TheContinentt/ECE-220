#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------

// You are free to declare any private functions if needed.

// Introduction: This file implements a program to do sudoku game.
// BY using backtrack in thw main function, and some other 
// branch functions to determine whether the input is available.
// The function would automatically make out a solution for the sudoku game.
// For the solve_sudoku function, I use the structure from course wiki,
// and write some conditions myself. And this is the main introduction
// for my MP7.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
// This function checks whether the val is already appeared in the row;
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);
  int index;
  for (index=0;index<=8;index++){
    if (sudoku[i][index]==val){
      return 1;
    }
}
      return 0;
  // BEG TODO
<<<<<<< .mine
    int col_index;
    int return_value;
    for (col_index = 0; col_index < 9; col_index++)
      {
        if (sudoku[i][col_index] == val)
        {
          return_value = 1;
          break;
        }
        else
        {
          return_value = 0;
        }
      }

  return return_value;
=======
>>>>>>> .r21845
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
// The function checks whether the val is already appeared in this column
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);
  int index;
  for (index=0;index<=8;index++){
    if (sudoku[index][j]==val){
      return 1;
    }
}
      return 0;

  // BEG TODO
<<<<<<< .mine
  int row_index;
  int return_value;
  for (row_index = 0; row_index < 9; row_index++)
    {
      if (sudoku[row_index][j] == val)
      {
        return_value = 1;
        break;
      }
      else
      {
        return_value = 0;
      }
    }
  return return_value;
=======
>>>>>>> .r21845
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
// The function checks whether this val is already appeared in the 3*3 squares.
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9);
<<<<<<< .mine

=======
  int a,b,RowIndex,ColIndex;
  a=i-i%3;
  b=j-j%3;
  for (RowIndex=0;RowIndex<=2;RowIndex++){
    for (ColIndex=0;ColIndex<=2;ColIndex++){
    if (sudoku[a+RowIndex][b+ColIndex]==val){
      return 1;
    }
    }
>>>>>>> .r21845
  // BEG TODO
<<<<<<< .mine
  int row_index;
  int col_index;
  int return_value = 0;
  col_index = j;
  row_index = i;
  if (i % 3 == 0)
  {
    if (j % 3 == 0)
    {
      for (row_index = i; row_index <= i + 2; row_index++)
      {
        for (col_index = j; col_index <= j + 2; col_index++)
        {
          if (sudoku[row_index][col_index] == val)
          {
            return_value = 1;
          }
        }
      }
    }
    else if (j % 3 == 1)
    {
      for (row_index = i; row_index <= i + 2; row_index++)
      {
        for (col_index = j - 1; col_index = j + 1; col_index++)
        {
          if (sudoku[row_index][col_index] == val)
          {
            return_value = 1;
          }
        }
      }
    }
    else if (j % 3 == 2)
    {
      for (row_index = i; row_index <= i + 2; row_index++)
      {
        for (col_index = j - 2; col_index <= j; col_index++)
        {
          if (sudoku[row_index][col_index] == val)
          {
            return_value = 1;
          }
        }
      }
    }
  }
  else if (i % 3 == 1)
  {
      if (j % 3 == 0)
      {
        for (row_index = i - 1; row_index <= i + 1; row_index++)
          {
            for (col_index = j; col_index = j + 2; col_index++)
            {
              if (sudoku[row_index][col_index] == val)
              {
                return_value = 1;
              }
            }
          }
      }
      else if (j % 3 == 1)
      {
        for (row_index = i - 1; row_index = i + 1; row_index++)
        {
          for (col_index = j - 1; col_index = j + 1; col_index++)
          {
            if (sudoku[row_index][col_index] == val)
            {
              return_value = 1;
            }
          }
        }
      }
      else if (j % 3 == 2)
      {
        for (row_index = i - 1; row_index = i + 1; row_index++)
        {
          for (col_index = j - 2; col_index = j; col_index++)
          {
            if (sudoku[row_index][col_index] == val)
            {
              return_value = 1;
            }
          }
        }
      }
  }
  else if (i % 3 == 2)
    {
      if (j % 3 == 0)
      {
        for (row_index = i - 2; row_index = i; row_index++)
        {
          for (col_index = j; col_index = j + 2; col_index++)
          {
            if (sudoku[row_index][col_index] == val)
            {
              return_value = 1;
            }
          }
        }
      }
      else if (j % 3 == 1)
      {
        for (row_index = i - 2; row_index = i; row_index++)
        {
          for (col_index = j - 1; col_index = j + 1; col_index++)
          {
            if (sudoku[row_index][col_index] == val)
            {
              return_value = 1;
            }
          }
        }
      }
      else if (j % 3 == 2)
      {
        for (row_index = i - 2; row_index = i; row_index++)
        {
          for (col_index = j - 2; col_index = j; col_index++)
            {
              if (sudoku[row_index][col_index] == val)
              {
                return_value = 1;
              }
            }
        }
      }
    }
  return return_value;
}  // END TODO
=======
  // END TODO
>>>>>>> .r21845
}
return 0;
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
// The function read the return value from the previous three check functions. 
// If return value is 1, that means val could not be input in the current location.
// After check the availability of the input, it returns 0 to main function if it succeeds, 
// otherwise it returns 0.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);
  // BEG TODO
<<<<<<< .mine
  int resultt;
  int return_value = 0;
  resultt = is_val_in_row(val, i, sudoku[9][9]);
  if (resultt == 1)
  {
    return_value = 1;
  }
  resultt = is_val_in_col(val, j, sudoku[9][9]);
  if (resultt == 1)
  {
    return_value = 1;
  }
  resultt = is_val_in_3x3_zone(val, i, j, sudoku[9][9]);
  if (resultt == 1)
  {
    return_value = 1;
  }
  return return_value;
=======
  if(val<0 || val>9 || is_val_in_3x3_zone(val,i,j,sudoku) || is_val_in_col(val,j,sudoku) || is_val_in_row(val,i,sudoku))
  return 0;
  // END TODO
  else
  return 1;
>>>>>>> .r21845
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
// THis function set the main function to solve the sudoku. I use the structure from the course 
// wiki and write some conditions to make it available to work.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
<<<<<<< .mine
  int num;
  int ii,jj;
  int i, j;
  int counter = 0;
  for (ii = 0; ii < 9; ii++)
  {
    for (jj = 0; jj < 9; jj++)
    {
      if (sudoku[ii][jj] == 0)
      {
        counter = counter + 1;
      }
    }
  }
  if (counter == 0)
  {
      return 1;
  }
  else
  {
      for (ii = 0; ii < 9; ii++)
      {
        for (jj = 0; jj < 9; jj++)
        {
          if (sudoku[ii][jj] == 0)
          {
            break;
          }
        }
      }
  }
    for (int num = 1; num <= 9; num++) {
      if (is_val_valid(num, ii, jj, sudoku[9][9]) == 0)
      {
        sudoku[ii][jj] = num;
        if (solve_sudoku(sudoku))
        {
          return 1;
        }
        sudoku[ii][jj] = 0;
      }
    }
    return 0;
=======
  int i,j,c,d,num;
  for(i=0;i<9;i++){
      for(j=0;j<9;j++){
>>>>>>> .r21845

<<<<<<< .mine

=======
              if (sudoku[i][j]!=0)  {
                if(i==8&&j==8){
  		              return 1;
  	             }   
	           }

	            else {
		              c=i;d=j;
                  goto CONTINUE;
	             }

	     }
     }
CONTINUE:
     for (num=1;num<=9;num++){
       if(is_val_valid(num,c,d,sudoku)){
           sudoku[c][d]=num;
               if(solve_sudoku(sudoku)){
               return 1;
               }
           sudoku[c][d]=0;
     }
   }

          return 0;


>>>>>>> .r21845
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
<<<<<<< .mine
=======

>>>>>>> .r21845
