#include <stdio.h>

/*	print Fahrenheit-Celsius table
		for fahr = 0, 20, ..., 300 */

float FtoC (float F){
	return (5.0/9.0) * (F - 32.0);
}


void main(){
	float fahr;
	float lower, upper, step;

	printf("Please enter at which temperature (°F) you want to start and end: ");
	scanf("%f %f", &lower, &upper);

	printf("Now, enter the step at which you want to increment the calculation: ");
	scanf("%f", &step);

	printf("=======================================\n");
	printf("==== Fahrenheit-Celsius convertion ====\n");

	for(fahr = lower; fahr <= upper ; fahr+=step){
		printf("\t%3.0f°F = ", fahr);
		printf("%2.1f°C \n", FtoC(fahr));
	}
	printf("======================================= \n");
}