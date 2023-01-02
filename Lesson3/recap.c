#include <stdio.h>

//#define DEBUG
int pointer();
int cast();
int implicitConversion();
int recap();

int main()
{
    printf("RECAP\n");
    recap();

    printf("implicitConversion\n");
    implicitConversion();

    printf("CAST\n");
    cast();

    printf("POINTER\n");
    pointer();

    return 0;
}

int pointer()
{
    
    return 0;
}


int cast()
{
    int i = 0;
    float f = 2.3;

    i = 2 * 1.8;
    printf("i:%d\n", i);

    i = (int)f * 2 + 0.5;
    printf("i:%d\n",i);

    i = f * 2 + 0.5;
    printf("i:%d\n", i);

    return 0;
}

int implicitConversion()
{
    int i = 1.5;
    float f = 0.0;

    printf("i:%d\n",i);

    f= i;
    printf("f:%f\n",f);

    i = f*3/2;
    printf("i:%d\n",i);

    i = i+0.6;
    printf("i:%d", i);

    f = i*2.4;
    printf("f:%f\n",f);

    return 0;
}

int recap()
{
    //int i = 3;
    //int j;
    //j=++i++ this will give an error as the result of the first increment
    //is a number and not an address needed for the increment operator.

    int i=1, j=1, k=1;
    int c,d,e;

#if 0
    printf("DEBUG MODE ACTIVATED\n");
    c = ++i + i++;
#else
    c = ++i + (i+=1);
#endif    

    e = k++ + ++k;

    d = ++j;
    d = d + j++;

    printf("i:%d j:%d k:%d\n", i,j,k);
    printf("c:%d d:%d e:%d\n", c,d,e);

    return 0;
}