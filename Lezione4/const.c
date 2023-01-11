#include <stdio.h>

int main()
{
    //const int n;
    int n = 0;
    const int *p = &n;

    int * const r = &n;

    //What is pointed by *p is constant since *p is a const int *
    *p +=1;
    *r += 1;

    p += 1;
    //Since r is a constant pointer you can't change the
    //address value contained in r which is the address of n.
    r += 1;

    return 0;
}