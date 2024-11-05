#include <stdio.h>
#include <stdlib.h>

//function prototype for matrix_mul
void matrix_mul(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main(void){
    //Declare variables
    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];

    int i, j, k; //Loop variables

    //initialise C_ij = 0
    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
	    C[i][j] = 0.0;
        }
    }

    //initialise A_ij = i + j
    for(i = 0; i < n; i++){ 
	for(j = 0; j < q; j++){
            A[i][j] = i + j + 2;
	}
    }

    //initialise B_ij = i - j
    for(i = 0; i < p; i++){
	for(j = 0; j < q; j++){
	    B[i][j] = i - j;
	}
    }

    //Calculate AB = C
 
    matrix_mul(n, p, q, A, B, C);

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
