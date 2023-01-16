#include <stdio.h>

#define SIZE    2
#define SQX     3
#define SQY     5

#define RANGE   SIZE

int main()
{
    int a[SIZE];
    int *b[SQY] = {NULL}, *p, **q;
    int c[SQY] = {2,3};

    int e[] = {2,3,4,5,6};
    
    int d[][SQX] = {1,2,3,4,5,6};

    for(int i=RANGE; i >= 0; i--)
    {
        a[i] = 0;
    }

    /*Sizeof will print the current size of the array, so
    * if there are two elements (like in array a there are two 0s)
    * it will print "8" as ints are 4 bytes long.
    * While b is 40 since it's an array of 5 pointers to ints.
    * In 64bits OS int pointers are 8 bytes. 4 bytes in 32bits OS.
    */
    printf("Size of a: %ld\n", sizeof(a));
    printf("Size of b: %ld\n", sizeof(b));
    printf("Size of c: %ld\n", sizeof(c));
    printf("Size of d: %ld\n", sizeof(d));
    printf("Size of e: %ld\n", sizeof(e));

    return 0;
}