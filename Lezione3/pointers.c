#include "pointers.h"

int main()
{
    /*Declarations:
    In order to declare a variable you just need to write:
    <type> identifier
    In order to declare a pointer you just need
    <type>* identifier
    */

    //You should always initialize a pointer
    //Example
    //int a = 0;
    //int *p = &a;

    //Pointers can be constant.

    //You can have void pointers.
    //You cannot call that void pointer since you cannot
    //know what the void pointer contains.
    int a = 10;
    char b = 'x';
    void *p;
    p = &a;
    p = &b;

    printLong();
    operationsWithPointers();

    return 0;
}

void printLong()
{
    //When a variable is like 0xSOMETHING it means it's an HEX.
    long var = 0x0deadbeef;

    long *p;
    p = &var;

    printf("%lx\n", (unsigned long)&var);
    printf("%lx\n", (unsigned long)p);
    printf("%lx\n", (unsigned long)var);
    printf("%lx\n", (unsigned long)*p);
    printf("%lx\n", (unsigned long)*(&var));
    printf("%lx\n", (unsigned long)p);
    printf("%lx\n", (unsigned long)&p);
    //This is an example of double pointer or pointer to pointer
    printf("%lx\n", (unsigned long)**(&p));
}

void operationsWithPointers()
{
    int a=0, b=0, *pa;
    
    //a+1=6; - This instruction is illegal.
    //This line is legal as what we're saying is:
    //Get the memory location of pa, point to it, get the next
    //memory block and set it 6.
    *(pa+1) = 6;
    
    pa = &(a+1);
    //This line is illegal as you cannot reference the number 4
    //in memory
    pa = &4;
    pa = &a+1;
}