#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
int gcd_rec(int a, int b);

int main(void){
    
    int a, b;
    
    printf("Give me two positive integers\n");
    scanf("%d %d", &a, &b);

    printf("The gcd is %d\n", gcd(a, b));
    printf("Using the recursion method: %d\n", gcd_rec(a, b));
    return 0;
}

int gcd(int a, int b){
    int temp;

    while (b != 0){
        temp = b;
        b = a%b;
	a = temp;	
    }

    if(a > 0) {
	return a;
    }
    else{
    return -1*a;
    }
}

int gcd_rec(int a, int b){

    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
