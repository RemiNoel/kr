#include "calc.h"

int bufp = 0;		// next free position in buf
char buf[BUFSIZE];	// buffer for ungetch()


// get a (possibly pushed-back) character from input
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// stop fetching user input and push character back on input buffer
void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
