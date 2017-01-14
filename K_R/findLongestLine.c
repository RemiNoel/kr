#include <stdio.h>

/*Print the longest input line*/

#define MAXLINE 1000

int getLine(char s[], int limit);
void copy(char[], char[]);


int main(){
	
	int len = 0;			// current line length
	int max = 0;			// maximum length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here

	while((len = getLine(line, MAXLINE)) > 0){
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) // there was a line
		printf("%s", longest);

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

// copies characters from an array to another array.
void copy(char to[], char from[]){
	int i = 0;
	// Continue to copy each character as long as we are not at the end of the string 
	while((to[i] = from[i]) != '\0')
		++i;
}
