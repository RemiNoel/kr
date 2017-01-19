#include <stdio.h>
#include <limits.h>

/*
	Program with some Bit manipulation functions
*/

unsigned getBits(unsigned, int, int);
unsigned getBits_2(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);
unsigned rightrot(unsigned, int);
int bitcount(unsigned);

int main(){
	unsigned x;
	unsigned y;
	int n;
	int p;

	printf("This programs does bit manipulation on a number that you enter. \n");
	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
	printf("Enter position p: ");
	scanf("%d", &p);
	printf("Enter number of bits n: ");
	scanf("%d", &n);

	//printf("Your test number 'x' = %u has been processed to the number: %u.\n", x, getBits_2(x,p,n,y));
	//printf("Your test number 'x' = %u has been processed to the number (inverted n-bits): %u.\n", x, invert(x,p,n));
	//printf("Your test number 'x' = %u has been processed to the number (right rotation): %u.\n", x, rightrot(x,n));
	printf("Your test number 'x' = %u has << %d >> bits that are 1s.\n", x, bitcount(x));

	return 0;
}

// get n-bits from position p in the least significant part of the number x
unsigned getBits(unsigned x, int p, int n){
	/*	The expression x >> (p+1-n) moves the desired field to the right
		end of the word. ~0 is all 1-bits; shifting it left n positions
		with ~0 << n places zeros in the rightmost n bits; complementing that
		with ~ makes a mask with ones in the rightmost n bits.
		Bit position start from 0.
				  MSB		  		LSB
		e.g. 	p = 4, n = 3 (shift >> 2)
				x = 00000001101.110.10 (442)
		#1. 	x = 0000000001101.110. (110)
		#2.		x = 0000000000000.110. (6)
	*/
	// Create n-bits mask
	unsigned mask = ~(~0 << n); 
	// Action #1 : shift right to make required bits right-justified
	unsigned x_right = (x >> (p + 1 - n));
	// Action #2 : return required bits
	return x_right & mask;
}

// returns x with the n-bits that begin at position p set to the rightmost n-bits of y, leaving the other bits unchanged
unsigned getBits_2(unsigned x, int p, int n, unsigned y){
	/*
		Wanted result for this problem is:
		(x & ForceRelevantBitsOff) | (yNBits << ShiftToRelevantPlace) 
	*/
	int shift = p + 1 - n;
	// Get the rightmost n-bits of y
	unsigned ybits = y & ~(~0 << n);
	// Shift to relevant position  
	unsigned yShift = ybits << shift;

	/* Mask to turn off X relevantBits
	   Mask = 00000001, n = 3 
	 	 	  00001000 - 1 
	   	 	  00000111 
	   	 	  Then shift to (p+1-n)*/

	unsigned xMask = (1 << n) - 1; 
	// Shift the mask to relevant position
	// Turn off the relevant bits. All the other bits must be 1 so the other bits of x remains unchanged
	xMask = ~(xMask << shift);

	// Then turn on the n-bits at position p with the right-most n-bits of y. 
	return (x & xMask | yShift); 
}

// Invert the n-bits from position p
unsigned invert(unsigned x, int p, int n){
	/*
		Wanted result for this problem is:
		(x & ForceRelevantBitsOff) | (xBitsInv << ShiftToRelevantPlace) 
	*/
	int shift = p + 1 - n;
	// Create n-bits mask
	unsigned mask = ~(~0 << n);

	// Create a mask that will be used on x to turn off relevant bits
	unsigned xMask = (1 << n) - 1; 
	// Shift the mask to relevant position
	xMask = xMask << shift;

	// Shift right to make required bits right-justified
	unsigned xRight = x >> shift;
	// Only keep the rightmost n-bits of x
	unsigned xBits = xRight & mask;
	// Shift the inverted bits to relevant place and invert bits
	xBits = ~(xBits << shift);
	// Only keep the relevant bits
	xBits = xBits & xMask;

	// invert the mask so the relevant bits will turn off those from x. 
	// Invert the n-bits at position p. 
	return (x & ~xMask | xBits); 
}

// Returns the value of x rotated to the right by n positions
// The the rightmost n-bits becomes the left most n bits
unsigned rightrot(unsigned x, int n){
	/*
		Wanted result for this problem is:
		1.(x >> ShiftToRelevantPlace)
		2. find the size of x (8,16 or 32 bits)
		3.(x | xLeftBits)
	*/
	unsigned xLeftBits = x & ~(~0 << n);
	unsigned xRightRot = x >> n;

	if(x >= 0 && x < UCHAR_MAX)
		xLeftBits <<= (8 - n);
	else if(x >= UCHAR_MAX && x < USHRT_MAX)
		xLeftBits <<= (16 - n);
	else if(x >= USHRT_MAX && x < UINT_MAX)
		xLeftBits <<= (32 - n);
	

	return xRightRot | xLeftBits;
}

// Returns the number of 1s (ones) a number contains
int bitcount(unsigned x){
	int b = 0;
	// Loop until x = 0. Remove the rightmost bit
	for(; x != 0; x &= (x-1))
		b++;

	return b;
}