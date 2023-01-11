#include "functions.h"

int main()
{
    int a = 3, b = 5;

    int *p;

    p = smaller(&a, &b);
    //We print the smallest element of the two.
    printf("%d\n", *p);

    /* You can create a pointer to a function 
    and in this way you can call the function pointed. */
    //(*p)()
    //To retrieve the element returned to the pointed function
    //you just need to call it like this:
    //*(*p)(&a, &b)

    return 0;
}


int* smaller(int *x, int *y)
{
    return (*x < *y ? x : y);
}

//Example pointers to function
int example()
{
    int f(int a);
    int (*pf)(int a);

    pf = f; //Initialize
    (*pf)(10); //Call
}