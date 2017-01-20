#include <stdio.h>
#include <ctype.h>

/*
	This programs expands shorthand notations like a-z to abc...xyz
*/
#define MAXLEN 1024


void expand(char[], char[]);


int main(){
	char command[50];
	char strList[MAXLEN];

	printf("This program takes a written command and expands it into a readable list\n");
	printf("e.g.: command = a-z  ->  list = abc...xyz\n\n");
	printf("Please enter your command:");
	scanf("%s",command);

	// put everything in lowercase 
	for(int i = 0; command[i] != '\0'; i++)
		command[i] = tolower(command[i]);

	expand(command, strList);

	return 0;
}

// Expand the written command into a readable list
void expand(char command[], char strList[]){
	//index of command and strList
	int i = 0, j = 0;
	// character used to expand the command into strList
	char ch;

	// go through command
	for(; command[i] != '\0'; ++i, ++j){
		/* 	put every into strList unless it is a command
			a command must start as : a-... or 0-...
			
			This part will work with alpha values
			*/
		if(isalpha(command[i]) && command[i+1] == '-' && isalpha(command[i+2])){
			ch = command[i];
			// expand the command into a chain of character
			for(; ch < command[i+2]; ++ch, ++j){
				strList[j] = ch;
			}
			// pass to the next command
			i++;
			// overwrite the '-' written from command
			j--;
		}

			//This part will work with numerical values
		else if(isdigit(command[i]) && command[i+1] == '-' && isdigit(command[i+2])){
			ch = command[i];
			// expand the command into a chain of character
			for(; ch < command[i+2]; ++ch, ++j){
				strList[j] = ch;
			}
			// pass to the next command
			i++;
			// overwrite the '-' written from command
			j--;
		}
		else
			strList[j] = command[i];
	}
	strList[j] = '\0';

	printf("Output: ");
	for(int index = 0; strList[index] != '\0'; ++index)
		printf("%c", strList[index]);
	printf("\n");
}
