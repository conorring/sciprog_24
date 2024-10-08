#include <stdio.h>
#include <math.h>

int main(void)   {
		
/* Declare variables */
   int a, N;
   float b, h, x, sum, result;

/* Initialise values for use in for loop */


   N = 12;  
   a = 0;
   b = M_PI/3;
   h = b/N; //Step size
   x = h; //For loop starts at x = h as we include tan(0) in sum1

   sum = tan(0) + tan(b); //Values at endpoints

   int i;
   for (i = 1; i < N; i++) {
   	sum = sum + 2*tan(x);
	x = x+h;
   } 
   
   result = ((b - a)/(2*N))*(sum);
   printf("Approximation using Trapeziodal Rule: %f\n", result);

/* Compare result to log(2) */
    printf("Difference between our result and theoretical result: %f\n", result - logf(2));

/* Find the absolute difference */
    printf("Relative error: %f\n", (fabs(result - logf(2)))/logf(2));

return 0;   
}
