#include <stdio.h>
#include <stdbool.h>

/* reads input and counts how many characters, word and newlines were in the stream.
   The program also remove excess spaces that where added as input
*/

#define OUT false 
#define IN  true

void main(){
	int c;
	long nc = 0;				// character count
	long nl = 0;  				// line count
	long nw = 0;				// word count
	bool excessSpace = false;	// tells if there is an excess of spaces ' ' in a string
	bool state = false;			/* the state of which tells if we are in a word or outside a word (for word counting)
								   true = IN to the word;	false = OUT of the word */

	// copy input to output
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++nl;

		// word count
		if(c== ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT){
				state = IN;
				++nw;		
		}

		if(c == ' '){
			if(!excessSpace){
				excessSpace = true;
				putchar(c);
			}
		}
		else{
			excessSpace = false;
			putchar(c);	
		}

	}
	printf("%ld characters read, %ld words counted %ld lines entered \n", nc, nw, nl);
}