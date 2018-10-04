#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Introduction: This program is designed to compute the roots of polynomials given the coefficients.
//First step in this program is to calculate the difference of sign changes of coefficients on both bounds of the given range.
//If difference is 0, then no roots exist accorind to Budan theorem. In other case, we go to step 2
//In step 2, we use halley's method to copute exact value of roots. 
//In this program, I use several functions and return values to make program convient such as absolute value function, derivative function
//and second derivative functions. Then by returning value to main function, the main function is precise and accurate.
double abs_double(double y)
{
    //Change this to return the absolute value of y i.e |y|
	if (y < 0){
	y = 0 - y;
	}
	else if (y >=0){
	y = y;
	}
    return y;
}
//this function use if-else to output absolute value of input values.

double fx_val(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the polynomial at the value x
	double fff;
	fff = a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
    return fff;
}
//this function computes the value of f(x) by given coefficients and x values.

double fx_dval(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the derivative of the polynomial at the value x
	double ffff;
	ffff = 4*a*x*x*x+3*b*x*x+2*c*x+d;
	
    return ffff;
}
//this function computes first derivative values of f(x) input coefficients and x values.

double fx_ddval(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the double derivative of the polynomial at the value x
	double fffff;
	fffff = 12*a*x*x+6*b*x+2*c;
    return fffff;
}
//this function computes second derivative values of f(x) input coefficients and x values.

double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the root found starting from the initial point x using Halley's method
	double origin, first, second;
	double resultt, numerator, denominator;
	double ccc = 0;
	resultt = 1;
	while (resultt > 0.000001)
	{
		origin = fx_val(a,b,c,d,e,x);	
		first = fx_dval(a,b,c,d,e,x);
		second = fx_ddval(a,b,c,d,e,x);
		numerator = 2*origin*first;
		first = abs_double(first);
		denominator = 2*first*first-(origin*second);
		resultt = numerator / denominator;
		x = x - resultt;
		resultt = abs_double(resultt);
		ccc =  ccc + 1;
		if (ccc >= 10000)
		{
			x = 10000;
			break;
		}	
	}
    return x;
}
//this function calculate recursion of x by calling several functions listed before, then plug and compute the final values.
//Also I use while loop to determine whether the difference between two xs is more than 0.00001. In order to avoid the infinite loop, I use c as
//a counter and break the loop once c is greater than 10000. In the end, I return the x-value to main function.

int rootbound(double a, double b, double c, double d, double e, double r, double l)
{
    //Change this to return the upper bound on the number of roots of the polynomial in the interval (l, r)
	double sign;
	double counter = 0;
	double countter = 0;
	double m,n,p,t;
	m = b;
	n = c;
	p = d;
	t = e;
	b = 4*a*l+m;
	c = 6*a*l*l+3*m*l+n;
	d = 4*a*l*l*l+3*m*l*l+2*n*l+p;
	e = a*l*l*l*l+m*l*l*l+n*l*l+p*l+t;
	sign = a*b;
	if (sign < 0){
	counter = counter +1;
	}	
	sign = b*c;
	if (sign < 0){
	counter = counter +1;
	}	
	sign = c*d;
	if (sign < 0){
	counter = counter +1;
	}
	sign = d*e;
	if (sign < 0){
	counter = counter +1;
	}
	b = 4*a*r+m;
	c = 6*a*r*r+3*m*r+n;
	d = 4*a*r*r*r+3*m*r*r+2*n*r+p;
	e = a*r*r*r*r+m*r*r*r+n*r*r+p*r+t;
	sign = a*b;
	if (sign < 0){
	countter = countter +1;
	}	
	sign = b*c;
	if (sign < 0){
	countter = countter +1;
	}	
	sign = c*d;
	if (sign < 0){
	countter = countter +1;
	}
	sign = d*e;
	if (sign < 0){
	countter = countter +1;
	}
	counter = counter - countter;
	counter = abs_double(counter);
    return counter;
}
//this function calculates the sign changes at the location of r and l, seperately. then computes the difference of changes for these two values
//And the result is the final upper bound the number of roots. Then return the upper bound value to main function by return counter in the end.

int main(int argc, char **argv)
{
	double a, b, c, d, e, l, r;
	double ott,v,x;
	double storage = 0;
	FILE *in;

	if (argv[1] == NULL) {
		printf("You need an input file.\n");
		return -1;
	}
	in = fopen(argv[1], "r");
	if (in == NULL)
		return -1;
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);
	fscanf(in, "%lf", &c);
	fscanf(in, "%lf", &d);
	fscanf(in, "%lf", &e);
	fscanf(in, "%lf", &l);
	fscanf(in, "%lf", &r);
	ott = rootbound(a,b,c,d,e,l,r);
	if (ott == 0)
		{			
		printf("The polynomial has no roots in the given interval.\n");
		}
	else if (ott > 0 || ott < 0)
		{
		for (x = l; x <= r; x = x + 0.5)
			{
			v = newrfind_halley(a,b,c,d,e,x);
				if (v == 10000)
				{
				printf("No roots found.\n");
				}
				if (v < l || v > r)
				{
				v =  storage;
					if (v < 0 || v > 0)
						{
						printf("Roots found: %f\n",v);
						}
				}
				else if (v >= l && v <= r)
				{
				printf("Roots found: %f\n",v);
				storage = v;
				}
			}
		}
//This function is the main function. First it calls the rootbound function to determine how many roots may be available.
//It the return value is 0, then print that no roots are availbale for this polynomial. Else, go to call newrfind_halley function to determine and print the exact roots value.
//In order to use different starting values, we use a for loop here to let x has a gap value of 0.5. This is the main structure of this program



    //The values are read into the variable a, b, c, d, e, l and r.
    //You have to find the bound on the number of roots using rootbound function.
    //If it is > 0 try to find the roots using newrfind function.
    //You may use the fval, fdval and fddval funtions accordingly in implementing the halleys's method.
    
    
    fclose(in);
    
    return 0;
}


