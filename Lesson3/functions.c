#include <stdio.h>
#include "functions.h"



int main()
{
    /* Functions in C pass elements by value, so if we change the
    value of a variable inside the called function, it will make no change to the value of
    the variable in the caller function. Example:
    */

    int a = 0;
    printf("Value of a before calling downFun: %d\n",a);
    downFun(a, 15);
    printf("Value of a after calling downFun: %d\n",a);

    /* However, if the variable we pass in downFun is a global variable
    and in the code of the downFun function we reference the global variable
    then the value of the global variable is changed.*/

    /* It is common practice to define global variables in the header file.*/

    printf("Value of b before calling downFun: %d\n",b);
    /*In this case we pass the ADDRESS (using the & keyword) of the global b variable. In this way
    the function can modify directly the content of the memory address of b resulting
    into changing the value of b globally.*/
    downFunGlobal(&b, 15);
    printf("Value of b after calling downFun: %d\n",b);

    printPointers();
    operationsWithPointers();

    return 0;
}

void downFun(int x, int y)
{
    x -= y;
    return;
}

/*The first parameter of this function takes a POINTER (aka ADDRESS)
The second parameter takes an int value.
The * keyword means that it is the ADDRESS of the element, not the value.
if you print x, it prints the ADDRESS, while *x prints the CONTENT of the memory at x's address.
*/
void downFunGlobal(int *x, int y)
{
    *x -= y;
    return;
}

//Note about pointers. Learn that pointers make more sense when read right to left.

void legality()
{
    int c = 0;
    int *pc; //if you put void instead of int the line is legal as void then gets casted as int *
    //NULL is an illegal type of address. int *pc = NULL is ILLEGAL.
    pc = &c; //this line is also legal as pc is an int and an address is an INT.

    //This line is LEGAL. As 0 is an address. You shold NEVER do it.
    //pc = c;
    //This line is not legal as &c is an address, which is an INT but won't work.
    //*pc = &c;
    //This is fine as *pc is an int and c is an int as well.
    *pc = c;
    //& is called ampersend.

    //A pointer that points to no variable, contains the special null-pointer constant, NULL.

    return;
}

void printPointers()
{
    char a;
    char b;

    //The %p allows you to print pointers addresses.
    printf("%p\n%p\n", &a, &b);

    return;
}

void operationsWithPointers()
{
    //p and q are pointers to x.
    int x = 4;
    int *p = &x;
    int *q = &x;
    
    x = x + 3;
    printf("Value of x: %d\n", x);

    *p = 8;
    printf("Value of x: %d\n", x);

    *&x = *q + *p;
    printf("Value of x: %d\n", x);

    x = *p * *q;
    printf("Value of x: %d\n", x);

    return;
}
