#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>			// for isdigit() && isalpha()
#include <string.h>			// for memset() && strcomp()
#include <math.h>			// for sin, cos, exp && pow
#include <stdbool.h>


#define NUMBER 		'0'		// Signals that a number has been found
#define TEXT	 	'T' 	// Signals that text has been found 
#define MAXOP 		100		// Max number of operand + operation on a single line
#define BUFSIZE		100 	// Max buffer size
#define MAXVAL		100		// Max number of operand or operator (max stack size)


extern int sp; 				// next free stack position
extern double val[MAXVAL];	// value stack

extern char line[BUFSIZE];	// line saved from user input
extern int  line_index;		// index of which line is being read
extern int  line_len;		// length of the entered line


// Gets the next operand or operation on the stack
int getop(char str[]);

// Pushes an operand or operation unto the stack
void push(double num);

// Pops an operand or operation off the stack
double pop(void);

// Clears the stack
bool clrStack(void);

// get the user-entered RPN command and return length of entered line
int getLine(char s[], int limit);

// Print the stack
void viewstack(void);

// Duplicate the top element of the stack
void duplicateTop(void);

// Swap the two top elements in the stack
void swapTop(void);

// Print the top element on the stack
void viewTopElem(void);

// Find the corresponding function based on a user command
void findFunction(char substr[]);

// Print the commands
void showCommands(void);

#endif //!MY_STACK_H