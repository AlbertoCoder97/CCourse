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

    printf("Size of a: %ld\n", sizeof(a));
    printf("Size of b: %ld\n", sizeof(b));
    printf("Size of c: %ld\n", sizeof(c));
    printf("Size of d: %ld\n", sizeof(d));
    printf("Size of e: %ld\n", sizeof(e));

    return 0;
}