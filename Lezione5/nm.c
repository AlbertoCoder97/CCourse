#include <stdio.h>
/* You can convert the source code to object modules
* using the command nm <object|executable> */
//Example nm nm(.out)

/* The linker will tell you the addresses where the 
* functions/variable are stored in memory. 
* It is useful to see which symbols are used in a source/lib. */

/* files that are .so/.dll are objects dynamically loaded at run-time. */

int globalVariable = 0;

int main()
{   
    int x = 1;
    return 0;
}

void testFunction()
{
    printf("This function just prints!\n");
}