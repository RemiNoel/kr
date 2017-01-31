#include "calc.h"

// When compiling on Linux, add -lm to the arguments to ensure the correct linkage of <math.h>

/*
 	Reverse Polish notation calculator 
 */


int main(){
	int type;
	double op2;
	char op[MAXOP]; // input string
	short i = 0;

	showCommands();

	while((type = getop(op)) != '\0'){
		switch(type){
			case NUMBER:
				push(atof(op));
				break;
			case TEXT:
				findFunction(op);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: division by zero\n");
				break;
			case '%':
				op2 = pop();
				if(op2)
					push(fmod(pop(), op2));
				else
					printf("error: division by zero\n");
				break;	
			case '#':
				duplicateTop();
				break;	
			case '~':
				swapTop();
				break;	
			case '^':
				viewTopElem();
				break;	
			case '!':
				if(clrStack())
					printf("Stack cleared\n");
				break;
			case '?':
				showCommands();
				break;		
			case '\n':
				printf("hello\n");
				printf("Your expression = %.8g\n", pop());
				break;
			default:
				printf("error: unknown command: %s\n", op);
				break;
		}
	}
	exit(EXIT_SUCCESS);
}