//in this c program to print every row in pascal triangle, I devide the combination number to numerator 
//part and denominator part. First I use one for loop to compute the numerator. And then I divide the denominator prat to 2 parts again.
//FIrst is k!, next is (n-k)!. These could be computed by two different for loops. And at the end multiply these numa and numb together
//Then result = numerator/denominator. In the end I use the printf format string %.0f to eliminate the decimal point of result. And this is the structure of my MP3.
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row_index;

  printf("Enter the row index : ");
  scanf("%d",&row_index);
	int b = 1;
	int c = 1;
	int k = 1;
	int m = 1;
	int z = 1;
	int r = 1;
	double numa = 1;
	double numb = 1;
	double numerator = 1;
	double denominator = 1;
	double result = 1;
//the part before I initialize several integers as counters in different for loops. And double some number to avoid overflow in computation.
	if (row_index > 0)
	{	
		for (b = 1; b <= row_index; b++)	
		{
			numerator *= b;
		}		
	 	printf("%d ", m);
//first compute numerator by using one for loop. And for convenience I print the first "1" in each row here instead of print it in each for loop.		
		for (k = 1; k < row_index; k++)
		{
			for (z = k; z < row_index; z++)
			{
				c = row_index - z;
				numb = numb * c;
			}	
//compute the factorial of k
			for (r = k; r >= 1; r--)
			{
				numa = numa * r;
			}	
//compute the factorial of n-k
		denominator = numa * numb;
		result = numerator / denominator;
		printf("%.0f ",result);
//print out the result to an integer
		numa = 1;
		numb = 1;
//initialize the numa and numb for next loop
		}
	printf("%d",m);
	printf("\n");
//print out the last element "1" in each loop
	}
	else if (row_index == 0)
	{
	result = 1;
	printf("%.0f\n",result);
//if row_index is 0, for loop does not exist. Thus list the case row_index == 0to a new branch here.
	}
  // Your code starts from here

  return 0;
}
