#include <stdio.h>

/* Parameters to main. */
/* The first parameter argc indicates to the program how many parameters where passed via commandline.
/ The second parameter argv are the actual parameters passed. */
int main(int argc, char *argv[])
{
    //Since argc is an int you can make checks whether there are a specific amount of parameters.
    if(argc != 3)
    {
        fprintf(stderr, "Usage: <nStrings> <stringLen>\n", argv[0]);
        return 1;
    } 
    return 0;
}