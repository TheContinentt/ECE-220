/*			
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */


/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */



#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

//INTRODUCTION: In this prog5.c program, I write three functions: set_seed, start_game and guess_number.
//In the set_seed function, I use sscanf to determine whether the input is a valid seed. I set a SECOND
//integers and POST array to judge whether extra numbers and character are achieved. In the second function
//I call rand function to get four random solutions. ANd assign them to the pointer: one, two, three and four.
//IN the last part, I first determine whether the guess is valid by using sscanf which is the same as the set_seed function.
//Then I set two arrays, one is the guess one and the other is the solution one. I compare these two arrays to determine how many perfect
//matches and misplacement matches are included. Eventually I print these two numbers and return the R value to the main function.



static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the 
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid. 
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
	int sign;
	int second = 0;
	int seed = 0;
	char post[2] = {0, 0};
	sscanf (seed_str, "%d%1s%d", &seed, post, &second);
	if (second == 0)
	{
		if (seed != 0)
		{
			if (post[0] != 0)
			{
			sign = 0;
			printf("set_seed: invalid seed\n");
			}
			else
			{
			sign = 1;
			}
		}
		else if (seed == 0)
		{
		sign = 0;
		printf("set_seed: invalid seed\n");
		}
	}
	else
	{
	sign = 0;
	printf("set_seed: invalid seed\n");
	}
	if (sign == 1)
	{
	srand(seed);
	}
	    return sign;
}
	
//COMMENT: In this part, I first sscanf the input string to get the integer seed. If extra char or numbers are achieved
//By using if-else statement, we could set the return variable sign to 0 or 1 seperately. Before we return the SIGN 
//to main function, we need to call srand function in order to use in the second part.






//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read. 
//    We declare
//    int seed;
//    char post[2];
//    The sscanf statement below reads the integer into seed. 
//    sscanf (seed_str, "%d%1s", &seed, post)
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully. 
//    Check that the return value is 1 to ensure the user enters only an integer. 
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary. 
//    You may need to change the return statement below
   


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above. 
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 8)
 *          *two -- the second solution value (between 1 and 8)
 *          *three -- the third solution value (between 1 and 8)
 *          *four -- the fourth solution value (between 1 and 8)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
	int counter = 0;
	int temp;
	int arrayyy[4];
	for (counter = 0; counter < 4; counter++)
	{
	temp = rand();
	temp = temp % 8;
	temp = temp + 1;
	arrayyy[counter] = temp;
	}
	guess_number = 1;
	solution1 = arrayyy[0];
	solution2 = arrayyy[1];
	solution3 = arrayyy[2];
	solution4 = arrayyy[3];
	*one = solution1;
	*two = solution2;
	*three = solution3;
	*four = solution4;

    //your code here
    
}

//COMMENT: In this second part, I first call the rand function to generate a 'random' number. And by using modulus and temporary 
//variable, I get one integer from 1 to 8. Then using for loop, I could get all four solutions. Then store them in four static integers
//in order to be used in the third function.





/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str. 
 *               The function must gcc -g -std=c99 -Wall -Werror test.c prog5.c -o test5calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-8). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.printf("%d  %d  %d  %d  \n", solution1, solution2, solution3, solution4);
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 8)
 *          *two -- the second guess value (between 1 and 8)
 *          *three -- the third guess value (between 1 and 8)
 *          *four -- the fourth color value (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 8), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess) 
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two, 
	    int* three, int* four)
{
	int v, vv, vvv, vvvv;
	int vvvvv = 0;
	char postt[2] = {0,0};
	int r = 0;
	int pc = 0;
	int mc = 0;
	int guesss[4] = {0,0,0,0};
	int solve[4] = {0,0,0,0};
	int ii, jj;
	int sss = 0;
	int counterr = 0;
	sscanf(guess_str, "%d%d%d%d%1s%d",&v, &vv, &vvv, &vvvv, postt, &vvvvv);
	if (vvvvv != 0)
	{
	r = 0;
	}
	else if (vvvvv == 0)
	{
		if (postt[0] != 0)
		{
		r = 0;
		}
		else if (postt[0] == 0)
		{
			if (v > 8 || v < 1)
			{
			counterr = counterr;
			}
			else 
			{
			counterr = counterr + 1;
			}
			if (vv > 8 || vv < 1)
			{
			counterr = counterr;
			}
			else
			{
			counterr = counterr + 1;
			}
			if (vvv > 8 || vvv < 1)
			{
			counterr = counterr;
			}
			else
			{
			counterr = counterr + 1;
			}
			if (vvvv > 8 || vvvv < 1)
			{
			counterr = counterr;
			}
			else
			{
			counterr = counterr + 1;
			}
			if (counterr == 4)
			{
			r = 1;
			}
			else
			{
			r = 0;
			}
		}
	}
	if (r == 0)
	{
	printf("make_guess: invalid guess\n");
	}
//check if guess is valid
	else if (r == 1)
	{
	*one = v;
	*two = vv;
	*three = vvv;
	*four = vvvv;
	guesss[0] = v;
	guesss[1] = vv;
	guesss[2] = vvv;
	guesss[3] = vvvv;
	solve[0] = solution1;
	solve[1] = solution2;
	solve[2] = solution3;
	solve[3] = solution4;
	for (ii = 0; ii < 4; ii = ii + 1)
	{
		if (guesss[ii] == solve[ii])
		{
			pc += 1;
			guesss[ii] = 9;
			solve[ii] = 9;
		}
	}
	ii = 0; 
	for (ii = 0; ii <= 3; ii++)
	{
		for (jj = 0; jj <= 3; jj++)
		{
			sss = 0;
			if (guesss[ii] == 9)
			{
				break;
			}
			if (jj == ii)
			{
				if (jj == 3)
				{
					break;
				}
				else
				{
					jj = jj + 1;
				}
			}
			if (solve[jj] == 9)
			{
				sss = 1;
			}
			if (sss == 1)
			{
				mc = mc;
			}
			else if (sss == 0)
			{
				if (guesss[ii] == solve[jj])
				{
					mc = mc + 1;
					guesss[ii] = 9;
					solve[jj] = 9;
				}
			}
		}
	}
	printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n", guess_number, pc, mc);
	guess_number = guess_number + 1;
	}







	return r;

}

//COMMENT: In this third function, I first use sscanf to determine whether the guess string is valid or not.
//If it's valid, I set two arrays, one is for guess and the other is for solutions. I first use a for loop to compare
//them to determine how many perfect matches appeared. Then using two for loops at the same time to determine the number of 
//misplaced matches. At the end, I set a printf to print these two numbers. For the return value, 
//if input string is valid, set return value r = 1. otherwise the return value is set to be 0.






//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-8. If so, it is a valid guess
//  Otherwise, it is invalid.  
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed
    



