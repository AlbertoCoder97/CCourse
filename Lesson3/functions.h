/*
A function in C has a return value, a side effect or both.

The side effect occurs before the value is returned.

The functions' value is the value in the expression of the return statement.

A function can be called for its value (pure functional model), 
its side effect (as a subroutine)
or both

Functions in C pass parameters BY VALUE.
If you want to affect the element in the memory then you need to do it
yourself manually.

The function declaration (like a prototype) gives the information aboure
return value and parameters.

The function definition contains the code for a function.

Functions SHOULD be declared before being used.
If a function is CALLED but not DEFINED, the linker will fail.
*/

//Example function declaration. The declaration is usually done in the *.c file(s).
//<return_type> function_name(<par1>, <par2>, ..)

//Global variable
int b = 0;

int simpleFunction(double number, char character, int integer);
double sin(double x);

void downFun(int x, int y);
void downFunGlobal(int *x, int y);

void legality();

void printPointers();
void operationsWithPointers();