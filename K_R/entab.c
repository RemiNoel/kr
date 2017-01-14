#include <stdio.h>

//		This program replaces spaces in the input with a proper tab size.	

#define MAXBUFSIZE 1024

int main(){
	int Bufflen = 0;
	int Buffer[MAXBUFSIZE] = {0};
	int spaceCount = 0;
	const short spaceToTabs = 5; // 4 spaces for a tab

	// while there's something in the buffer
	while(Bufflen = getLine(Buffer, MAXBUFSIZE) > 0){
		// Continue until we are at the end of the Buffer
		for(int i = 0; Buffer[i] != '\0'; ++i){
			// Increment the number of spaces 
			if(Buffer[i] == ' ')
				++spaceCount;
			// Reset the space counter
			else
				spaceCount = 0;

			if(spaceCount == spaceCount){
				// go back to the start of read spaces and replace spaces with a tab
				i -= 4;
				Bufflen -= 4;
				Buffer[i] = '\t';

				/*	Now everything is offset, so we have to put everything back so the 
					buffer remains exact
				*/
				for(int j = 0; j < Bufflen; j++)
					Buffer[j] = Buffer[j+4];

				// Reset space counter
				spaceCount = 0;
				// Put the null symbol back at the end of the buffer
				Buffer[Bufflen] = '\0';
			}
		}
	}
	return 0;
}


// read a line into s, returns length of s
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