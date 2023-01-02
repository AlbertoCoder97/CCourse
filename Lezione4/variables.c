#include "variables.h"

int main()
{
    staticVariable();
    globalVariable();
    staticVariable();
    return 0;
}

//A static variable is local because you can reference the variable only within the function's block
//However the variable will stay "alive" throughout the program's execution and doesn't get "reset"
void staticVariable()
{
    static int staticVar = 0;
    printf("The current value of staticVariable is: %d\n", staticVar);
    staticVar += 1;
    printf("The value of staticVariable after increasing it is: %d\n", staticVar);
}

//Like static variables, global variables have a value in common for the whole program.
//And they are alive for the whole duration of the process' life.
//Changing the value of a global variable results into the change of the value for the whole program.
void globalVariable()
{
    printf("The value of the global variable is: %d\n", globalVar);
}