#include <stdio.h>
#include <stdbool.h>

/*
	This program returns the character and the index of the first occurrence of the same character in both strings.
	The index is based on the first string only.
*/

#define MAXBUFF 1024

struct pair{
	char c;
	int index;
};

struct pair any(char[], char[]);
bool isInStr(char, char[]);


int main(){
	
	char strA[MAXBUFF] = {};
	struct pair result;

	printf("This program prints the index of the first occurrence of the same character in both strings.\n");
	printf("Please enter the string you want to compare: ");
	scanf("%s", strA);

	printf("\nThe second string to which the first string will be compared to is: AFaeGuNcb\n");
	result = any(strA, "AFaeGuNcb");

	printf("The first character to repeat itself in both strings is << %c >> at index << %d >>", result.c,  result.index);

	return 0;
}

// Returns the index of the first char in strA that is also in strB
struct pair any(char strA[], char strB[]){
	struct pair temp;
	temp.c = '0';
	temp.index = -1;

	for(int index = 0; strA[index] != '\0'; index++){
		if(isInStr(strA[index], strB)){
			temp.c = strA[index];
			temp.index = index;
			return temp;	
		}
	}
	temp.c = '0';
	temp.index = -1;
	// if no chars are the same in both strings, return -1
	return temp;
}

// Returns true if a char c is in string str
bool isInStr(char c, char str[]){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == c)
			return true;
	}
	return false;
}