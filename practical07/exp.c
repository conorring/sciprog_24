#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int factorial(int x);

int main(void){
    
    int order;
    double *terms;

    printf("Please enter the order of the polynomial you want\n");
    scanf("%d", &order);
    
    terms = (double *) malloc(order * sizeof(double));
    int i;
    for(i = 0; i < order; i++){
        terms[i] = 1.0/ (double) factorial(i + 1);
    }
    
    double e = 1.0;
    for(i = 0; i < order; i++){
        e = e + terms[i];
    }
    free(terms);

    printf("e is estimated as %.10lf, with difference %e.\n", e, e - exp(1.0));

    return 0;
}

int factorial(int x){
    if (x < 0){
        printf("You must use a positive number\n");
	return (-1);
    }

    else if (x == 0){
        return 1;
    }

    else{
        return (x * factorial(x - 1));
    }



}
    
