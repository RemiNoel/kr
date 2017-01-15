#include <stdio.h>
#include <stdbool.h>

/*
	This program deletes each character in String1 that matches any character in String2.
*/

#define MAXBUFF 1024

void squeeze(char[], char[]);
bool isInStr(char, char[]);

int main(){
	
	char str[MAXBUFF] = {};

	printf("This program removes the letter from a string when compared to another string.\n");
	printf("Please enter the string you want to squeeze: ");
	scanf("%s", str);

	squeeze(str, "AFaeGuNcb");
	printf("Initial string with removed char: %s \n", str);	

	return 0;
}

// If a char from str is also in strMask, remove the char from str.
void squeeze(char str[], char strMask[]){
	int i = 0, j = 0;
	for(; str[i] != '\0'; i++){
		if(!isInStr(str[i], strMask))
			str[j++] = str[i];
	}
	str[j] = '\0';
}

// Returns true if a char c is in string str
bool isInStr(char c, char str[]){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == c)
			return true;
	}
	return false;
}