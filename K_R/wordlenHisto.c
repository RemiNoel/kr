#include <stdio.h>

void printWordLenHisto(int[]);
void printfreqCharHisto(int[]);

int main(void){
	int nword[22] = {0};	// array containing the frequency of the length of words in a stream
	int nchar[26] = {0};	// array containing the frequency of each letters in a stream
	short currentwlen = 0;	// current word length
	char c = 0;		// current character taken from the stream

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t'){
			++nword[currentwlen - 1];
			currentwlen = 0;
		}
		else
			++nchar[c - 'a'];
			++currentwlen;
	}
	//printWordLenHisto(nword);
	printfreqCharHisto(nchar);
	return 0;
}

// prints frequency of the length of words from the input
void printWordLenHisto(int arr[]){
	int index = 0;
	while(index < 22){
		printf("%d\t", index + 1);
		for(int j = 0; j < arr[index]; ++j)
			printf("*");
		printf("\n");
		++index;
	}
}

// prints the frequency of each letters from the input
void printfreqCharHisto(int arr[]){
	char index = 'a';
	while(index <= 'z'){
		printf("%c\t", index);
		for(int j = 0; j < arr[index - 'a']; ++j)
			printf("*");
		printf("\n");
		++index;
	}
}