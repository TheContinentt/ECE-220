#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,y,z;
	int a;
	double pi = 3.1415;
	float c;
	float m;
	printf("Enter the values of n, omega1, and omega2 in that order\n");
	scanf("%d,%d,%d", &n,&y,&z);
	for (a = 0 ; a < n ; a++){
		c = (a*pi)/n;
		m = sin(y*c)+(1/2)*sin(z*c);
		printf("(%f, %d,%f)\n",c,a,m);
		}
	return 0;	
}

