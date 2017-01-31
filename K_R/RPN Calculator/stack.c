#include "calc.h"

/*
	This file contains the code of the stack
*/

int sp = 0;			// next free stack position
double val[MAXVAL];	// value stack


// push an operand or operation unto the stack
void push(double num){
	if(sp < MAXVAL)
		val[sp++] = num;
	else
		printf("error: stack is full, can't push element %g \n", num);
}

// pop an operand or operation off the stack
double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack is empty\n");
		return 0.0;
	}
}

// print the stack
void viewstack(void){
	printf("\nstack: \n");
	for(int i = 0; i < sp; i++)
		printf("%.8g\n", val[i]);
}

// Duplicate the top element of the stack
void duplicateTop(void){
	if(sp > 1){
		double top = pop();
		push(top);
		push(top);
	}
	else
		printf("Invalid command. There must be at least 1 elements on the stack to use duplicateTop()\n");
}

// Switch the two top elements in the stack
void swapTop(void){
	if(sp > 2){
		double elem1 = pop();
		double elem2 = pop();
		push(elem1);
		push(elem2);
	}
	else
		printf("Invalid command. There must be at least 2 elements on the stack to use swapTop()\n");
	
}

// Print the top element on the stack
void viewTopElem(void){
	if(sp > 0){
		printf("%.8g\n", val[sp-1]);
	}
	else
		printf("The stack is empty\n");
}

// clear the stack
bool clrStack(void){
	if(sp > 0){
		sp = 0;
		memset(val, 0, sizeof(val));
		return 1;
	}
	else{
		printf("Error: stack empty\n");
		return 0;
	}

}
