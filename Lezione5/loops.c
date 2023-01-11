#include "loops.h"

int main()
{
    forLoop();
    whileLoop();
    doWhileLoop();

    return 0;
}

/* The most common loop type is the for loop. 
A loop is made by writing:
for(index; expression; update) { do stuff; }
Where the index is the element that gets indexed like int i = 0
then the expression is evaluated at every iteration, if it's true
it goes inside the for loop body and then the update
is where you usually increment/decrease the variable. */
void forLoop()
{
    for(int i = 0; i < 10; i++)
    {
        printf("For loop: %d\n", i);
    }
}

/* Anything inside the while loop 
is executed everytime the expression is true.
If it's not it exits.
You can have a break like in the switches
to break out of the loop.*/
void whileLoop()
{
    int x = 0;
    while(1)
    {
        printf("I'm an endless loop.\n");
        x++;
        if(x > 10) break;
    }
}


/* do while loop are the least common. This is their structure:
do
{do stuff;}
while(condition);*/
void doWhileLoop()
{
    int x = 0;
    do
    {
        printf("The value of x is: %d\n", x);
        x++;
    } while (x < 10);
    
}
