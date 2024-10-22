#include <stdio.h>
#include <stdlib.h>

//Declare fibonacci step function
void fibonacci(int *pf1, int *pf2);

int main(void) {
    int n; //Variable declarations

    printf("Type an integer greater than 1:"); //User message and input
    scanf("%d", &n);
    
    //Exit if invalid input is given
    if(n < 1) {
        printf("n must be an integer greater than 1\n");
	exit(1);
    }
    
    int F0 = 0, F1 = 1;

    printf("The series up to the %d th term is:\n", n);
    printf("%d %d ", F0, F1);

    int i;
    for(i = 2; i <= n; i++) {
	    if(i % 10 == 0) {
	        printf("\n");
	    }  
        fibonacci(&F1, &F0);
	printf("%d ", F1);
    }
    printf("\n"); 
    return 0;	
}

//Fibonacci step to recursively find next value
void fibonacci(int *pf1,int *pf2) {
    int f0;

    f0 = *pf1;
    *pf1 = *pf1 + *pf2;
    *pf2 = f0;
}
