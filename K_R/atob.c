#include <stdio.h>
#include <string.h>

/*
	This programs changes a decimal value into a user-chosen base (between 2 and 35 (0-Z))
*/

void atob(long long value, int b, char str[]);
void reverse(char str[]);

int main(){
	long long value;
	int base;
	char str[64];

	printf("This program changes an entered value into a chosen base.\n");
	printf("Enter the value you want to modify: ");
	scanf("%llu", &value);
	printf("Enter the base into which your entered value will be changed: ");
	scanf("%d", &base);

	atob(value, base, str);

	printf("%llu modified into base << %d >> is equivalent to: %s\n", value, base, str);

}

// Change decimal value into a number of base b
void atob(long long value, int b, char str[]){
	static char characters[38] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long long temp = value;
	char digit = 0;
	int i = 0;

	do{
		str[i++] = characters[value % b];
	} while(value /= b);

	if(temp < 0)
		str[i++] = '-';

	str[i] = '\0';

	// To display the correct value, str must be rotated
	// The last digit is reserved for the null operator
	reverse(str);
}

// Reverses a string 
void reverse(char str[]){
	int i = 0, j = strlen(str) - 1;
	char temp;
	for(; i < j; ++i, --j){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}