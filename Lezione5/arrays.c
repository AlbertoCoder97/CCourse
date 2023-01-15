#include "arrays.h"

int main()
{
    //This is an array of 9 elements with index starting 0 to 8,
    int scores[9];
    int RollNum[30][4];

    //This is an array of 9 pointers to integer.
    int * scores[9];

    //To declare a pointer to an array you need to put the pointer in brackets.
    //p is a pointer to an array of 4 elements (ignore the assignment to RollNum)
    int (*p)[4] = RollNum;

    return 0;
}