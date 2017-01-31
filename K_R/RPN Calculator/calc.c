#include "calc.h"

/*
	This file contains the code for the calculator driver
*/

char line[BUFSIZE];		// line saved from user input
int  line_len = 0;		// length of the entered line
int  line_index = 0;	// index of the char in the entered line

// get the next character or operand from the input
int getop(char str[]){
	// string index
	int i = 0;
	// contain the current character
	int c; 
	str[0] = '\0';

	if(line_len == 0 || line_index == (line_len - 2)){
		line_index = 0;
		line_len = getLine(line, BUFSIZE);
	}

	if(line[line_index] == '\n')
		return '\n';
	

	// skip the whitespaces
	while(isspace(c = line[line_index++]));
	str[i++] = c;


	// check if operand is a negative number or operator
	if(c == '-'){
		c = line[line_index++];

		// check if c is an operator
		if(c == ' ' || c == '\n'){
			line_index--;
			return '-';
		}
		else if(isdigit(c))
			str[i++] = c;
	}

	// when there's a character, check if it is a math function
	if(isalpha(c) && c != '.' && c != '-'){
		i = 1;
		// get the full substring and then check if it a known math function
		while(line[line_index] != '\n' && line[line_index] != ' ' && isalpha(line[line_index]))
			str[i++] = line[line_index++];

		str[i] = '\0';

		if(i > 1)
			return TEXT;
		else
			return c;
	}
	// check if a valid expression has been entered
	// it has to be numbers or a dot .
	else if(!isdigit(c) && c != '.' && c != '-')
		return c;


	// collect the integer part
	if(isdigit(c))
		// collect the complete integer
		while(isdigit(str[i++] = c = line[line_index++]));

	// collect the fraction part
	if(c == '.')
		while(isdigit(str[i++] = c = line[line_index++]));

	str[i] = '\0';

	return NUMBER;
}
	
// Find the corresponding function based on a user command
void findFunction(char substr[]){
	double op2;
	// If the string are the same (equal to 0)
	if(strcmp(substr, "sin") == 0)
		if(sp < 1)
			printf("Can't use the function %s. The stack must have at least 1 element. \n", substr);
		else
			push(sin(pop()));
	else if(strcmp(substr, "cos") == 0)
		if(sp < 1)
			printf("Can't use the function %s. The stack must have at least 1 element. \n", substr);
		else
			push(cos(pop()));
	else if(strcmp(substr, "tan") == 0)
		if(sp < 1)
			printf("Can't use the function %s. The stack must have at least 1 element. \n", substr);
		else
			push(tan(pop()));
	else if(strcmp(substr, "pow") == 0){
		if(sp < 2)
			printf("Can't use the function %s. The stack must have at least 2 element. \n", substr);
		else{
			op2 = pop();
			push(pow(pop(), op2));
		}
	}
	else if(strcmp(substr, "exp") == 0)
		if(sp < 1)
			printf("Can't use the function %s. The stack must have at least 1 element. \n", substr);
		else
			push(exp(pop()));
	else
		printf("Unknown math function %s\n", substr);
}

// Print the calculator commands
void showCommands(void){
	printf("Reverse Polish Notation Calculator\n");
	printf("=================================================\n");
	printf("This is a Reverse Polish notation calculator.\n");
	printf("You must enter an equation as following:\n");
	printf(" 1 2 - 4 5 + *\n");
	printf(" eq: (1 - 2) * (4 + 5) = -9\n");
	printf("=================================================\n");
	printf("+ : Add\n");
	printf("- : Substract\n");
	printf("* : Multiply\n");
	printf("/ : Divide\n");
	printf("%% : Modulo\n");
	printf("sin : Sine function\n");
	printf("cos : Cosine function\n");
	printf("tan : Tangent function\n");
	printf("pow : Power function\n");
	printf("exp : exposant (base e) function\n");
	printf("# : Duplicate the top of the stack\n");
	printf("~ : Swap the two top elements on the stack\n");		
	printf("^ : View top element on the stack\n");
	printf("! : Clear the stack\n");
	printf("=====================================================================\n");
	printf("To stop the calculator, press ctrl+D on Linux or ctrl+Z on Windows.\n");
	printf("=====================================================================\n");
}

// get the user-entered RPN command and return length of entered line
int getLine(char s[], int limit){
	//c holds a char, i will be the length of s
	int c, i;

	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < limit - 1; i++)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	// complete the C-string
	s[i++] = '\0';

	return i;
}