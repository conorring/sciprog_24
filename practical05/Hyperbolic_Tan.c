#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double arctanh1(double x, double delta);
double arctanh2(double x);

int main(void) {

    //Declare variable for input
    double delta;
   
    printf("Input a positive real number: \n");
    scanf("%lf", &delta);

    //delta must be greater than 0 for our loop to eventually break
    if(delta < 0) {
        printf("Number must be positive\n");
	exit(1);
    
    }

    //Declare variables for use in loop: start at x = -0.9 and store values in tan1, tan2
    double x = -0.9;
    int length = 1000;
    double tan1[length];
    double tan2[length];
    int i = 0;

    while (x<= 0.9 && i < length) {
    	tan1[i] = arctanh1(x, delta);
	tan2[i] = arctanh2(x);
        
	//Compare accuracy to 10 sig figs
	printf("The difference at x = %lf is %.10lf \n",
			x, fabs(tan1[i] - tan2[i]));
	i++;
	x += 0.01;
    }
}

double arctanh1(double x, double delta) {
    double sum = 0;
    double elem, val;
    int n = 0;
    
    //Runs statement at least once
    do{
        val = 2*n + 1;
	elem = pow(x, val) / val;
	sum += elem;
        n++;
    } 

    while (fabs(elem) > delta);
    return sum;
}
        
double arctanh2(double x) {
        return 0.5*(log(1 + x) - log(1 - x));
}
