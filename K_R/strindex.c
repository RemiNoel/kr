#include <stdio.h>

/*
	This program checks for a pattern in a CLI written string 
	and returns the frequency of the pattern 
*/

#define MAXBUFF 1024

int getLine(char[], int);
int strIndex(char[], char[]);

// wanted pattern
char pattern[] = "ould";


int main(){
	char input[MAXBUFF];
	short found = 0;

	// continue while there's something written from the CLI 
	while(getLine(input, MAXBUFF) > 0){
		if((found = strIndex(input, pattern)) >= 0)
			;
	}
	printf("Pattern found are rightmost index: %d\n", found);
	return found;
}

// Find the index at which a certain pattern starts in str
int strIndex(char str[], char pat[]){
	int i, j, k;
	int tempIndex, rightIndex = -1;

	// Go through str
	for(i = 0; str[i] != '\0'; ++i){
		// Compare a part of str with the pattern
		// If there is a pattern, pattern[k] == '\0' will be true and terminate the loop
		// The index of the pattern k will be used to check if we have passed through the pattern
		for(j = i, k = 0; pat[k] != '\0' && str[j] == pat[k]; ++j, ++k)
			;
		if(k > 0 && pat[k] == '\0'){
			tempIndex = i;
			if(rightIndex < tempIndex)
			rightIndex = tempIndex;
		}
	}	
	return rightIndex;
}


// parse s, returns length of s
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