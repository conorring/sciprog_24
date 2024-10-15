#include <stdio.h>
#include <math.h>

#define N 12

// Declaring global variables
float tangent[N+1];
float degtorad(float arg);
float trap_area();


//Main returns our approximation of the integral using the trap rule
int main(void) {
	int i;
	float deg, b_deg = 60;
	
	// Stores values of tan for 13 angles between 0 and pi/3
	for(i = 0; i < N+1; i++) {
		deg = 5.0*i;
		tangent[i] = tan(degtorad(deg));
		printf("tangent[%d] = %f\n", i, tangent[i]); //Print values 
	} 
	
	//Print our final area calculation by calling trap_area
	printf("Area = %f\n", trap_area());
}


// Converts degrees to radians
float degtorad(float arg) {
	float pi = 3.1415927;
	return( (pi * arg)/180.00 );
}

// Implementing trap rule tan(x)
float trap_area(void) {
 	int i;
	float area = tangent[0] + tangent[N];

	for(i = 1; i < N; i++) {
		area = area + 2*tangent[i];
	}
	
	return (degtorad(60)/(2*N))*area;

}



