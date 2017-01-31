This folder contains the source files to compile a Reverse Polish notation Calculator.

Using GCC, compile using this commands:

gcc main.c calc.c stack.c -lm -o <name>


then to run the compiled file:

./<name>


Note: getch.c was previously used to read the user input from the command line, but got replaced by the function getLine(). It is kept in the folder only for consulting purposes.
