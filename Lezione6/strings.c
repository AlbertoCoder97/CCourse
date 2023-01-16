#include <stdio.h>
/* C doesn't have a NATIVE string data type.
* Strings in truth are just an one-dimensional array of chars. */

/* 'H' is a char.
* "H" = "H\0" is a string which is a pointer to an array of chars
* "" this is an empty string which contains only '\0' */

#define SIZE    10
#define STRING "AString"

int main()
{
    //This is legal!
    printf("%c\n", "Hello"[1]);

    char str[9]; //This is an array to char of 9 elements
    char* pStr; //This is a pointer to the first char of the chars

    char p[SIZE]; //This is on the stack.
    char *q=malloc(SIZE); //This is on the heap.

    char p1[] = {'A', 'B', 'C', '\0'}; //This is a unique string with address X
    char p2[] = {'A', 'B', 'C', '\0'}; //This is a unique string with address Y

    /* These two pointers point to the same memory area. */
    char *q=STRING;
    char *r=STRING;

    return 0;
}