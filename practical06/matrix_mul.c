#include <stdio.h>
#include <stdlib.h>

int main(void){
    //Declare variables
    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];

    int i, j; //Loop variables

    //initialise C_ij = 0
    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
	    C[i][j] = 0.0;
        }
    }

    //initialise A_ij = i + j
    for(i = 0; i < n; i++){ 
	for(j = 0; j < q; j++){
            A[i][j] = i + j + 2;                                                                                                }
    }

    //initialise B_ij = i - j
    for(i = 0; i < p; i++){
	for(j = 0; j < q; j++){
	    B[i][j] = i - j;
	}
    }

    //Calculate AB = C
    int k;
    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
	    for(k = 0; k < p; k++){
	        C[i][j] += A[i][k] * B[k][j];
	    }
	}
    }

    //Print out matrices
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
	    printf("%3.0f \t", A[i][j]);
	}
	printf("\n");
    }
    printf("\n");

    for(i = 0; i < p; i++){
        for(j = 0; j < q; j++){
	    printf("%3.0f \t", B[i][j]);
	}
	printf("\n");
    }
    printf("\n");

    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
	    printf("%3.0f \t", C[i][j]);
	}
	printf("\n");
    }






}
