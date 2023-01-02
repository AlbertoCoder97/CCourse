
#include <stdio.h>
void main(void)
{
    int a = 0;
    int b = 0;

    int x = 0;
    int y= 0;

    //In this case, first we assign the value of a in x and
    //then we increment a therefore x will be 0 and a will be 1.
    x = a++;
    printf("x = a++: %d\n", x);
    printf("a = %d\n", a);

    //In this case, first we increment b, then we assign the value in b
    //to y. Therefore y will be 1 same as b.
    y = ++b;
    printf("y = ++b: %d\n", y);
    printf("b = %d\n", a);

    int i = 3;
    int j;

    //This is an error as you cannot increment with the ++
    //something that is NOT A VARIABLE.
    //j = (i+2)++;

    j = i++ + 2;
    j = 2+ ++i;

    //Like the first case, we can only increment with the operator ++
    //VARIABLES or things that point to int values!
    //j= ++(i+2);

    //In the first and third example ++ is not pointing to a variable/address
    //it is "pointing" to a value, therefore it's an error.
    
    // the = is an operator. It assignes a value to a variable.
    // a = b means that a has the value of b.

    //+a, -a are also operators.

    //*=, += , /=, %=, -= are operations that are translated as:
    // x = x* expression etc...

    /* Type Conversion */
    /* There are two ways to convert an element's type. Implicit and 
    * Explicit (cast). It is MUCH better to use the Explicit conversion
    * with casts (<type>)<variable>
    */

   //Explicit conversion example
   int example = 0;
   double f = 3.14;
   example = (int)f;

    printf("Cast example: %d\n", example);

}