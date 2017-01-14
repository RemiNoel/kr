#include <stdio.h>
#include <stdbool.h>
/*
	Hex String to int converter
*/

#define MAXBUFF 1024

long long htoi(char[]);
int getLine(char[], int);
bool isHex(char);

int main(){
	char str[MAXBUFF];
	bool isHexStr = true;
	long long temp;

	printf("Enter a hexadecimal value :");

	// loops until EOF
	while (getLine(str, MAXBUFF) > 0){
		//Convert Hex string to equivalent decimal value
		temp = htoi(str);

		printf("you entered %lld in decimal value. \n", temp);
		printf("Try another one? \n");
	}



	return 0;
}


// Converts a Hexadecimal string to an integer
long long htoi(char arr[]){
	long long temp = 0;
	int i = 0;

	// Check the first two bits to separate them from the computation
	if((arr[0] == '0') && (arr[1] == 'x' || arr[1] == 'X'))
		i = 2;

	// converter
	while(isHex(arr[i])){
		if(arr[i] >= '0' && arr[i] <= '9')
			temp = 16*temp + (arr[i] - '0');
		else if (arr[i] >= 'a' && arr[i] <= 'f')
			temp = 16*temp + ((arr[i] - 'a') + 10);
		else if (arr[i] >= 'A' && arr[i] <= 'F')
			temp = 16*temp + ((arr[i] - 'A') + 10);
		else if(!isHex(arr[i])){
			printf("ERROR! You entered non-hexa values. \n");
			return -1;
		}
		++i;
	}
	return temp;
}

bool isHex(char test){
	if((test >= '0' && test <= '9') || (test >= 'a' && test <= 'f') || (test >= 'A' && test <= 'F'))
		return true;
	else
		return false;
}



// Parses s, returns length of s
int getLine(char s[], int limit){
	//c holds a char, i will be the length of s
	int c, i;

	for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	// complete the C-string
	s[i] = '\0';

	return i;
}