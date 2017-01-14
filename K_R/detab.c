#include <stdio.h>

/*		This program replaces tabs in the input with the proper number of blanks 
		to space to the next tab stop.	
*/

#define MAXBUFSZ 1000

int getLine(char[], int);
int calculateTabLen(int offSet, int tabSize);

int main(){
	int c;
	char Buffer[MAXBUFSZ] = {0};
	short tabSize = 5; 				// tabSize is for test purposes
	int temp;
	int posInBuff = 0;

	// While there's something in the read buffer
	while(getLine(Buffer, MAXBUFSZ) > 0){
		// Loop until we are at the end of the buffer
		for(int i = 0; Buffer[i] != '\0'; ++i){
			if(Buffer[i] == '\t'){
				// Calculate the number of spaces needed to replace the tab
				// Replace it by the calculated number of spaces needed
				for(int j = 0; j < calculateTabLen(posInBuff, tabSize) ; j++){
					putchar(' ');
					++posInBuff;
				}
			}
			else{
				putchar(Buffer[i]);
				++posInBuff;
			}
		}
	}
	return 0;
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

/*	This function calculates the number of spaces needed depending 
	on the size of tabsize but also the position we are in the buffer

	e.g.posInBuff = 453; tabSize = 5
		number of spaces needed = 5 - ( 453 % 5)
		Thus, we only need 2 spaces to replace the this tab

		This is needed because the tab size normally varies 
		between 2 and 8 spaces. We only choose 5 for test purposes
		 */
				//	 posInBuff		
int calculateTabLen(int offSet, int tabSize){
	return tabSize - (offSet % tabSize);
}