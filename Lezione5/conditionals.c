#include "conditionals.h"



int main()
{
    switchStatements();
    return 0;
}

/* Switch example */
/* switch(expression) {
    case constant-1: statement...
    case constant-2: statement
    etc...
}
You cannot use variables.
If you don't put a break, the switch executes
ALL the cases unless it gets out of the switch with the break.
The default case is called when the expression value is not in
any case. 
*/
void switchStatements()
{
    int x = 3;
    switch(x)
    {
        case 0:
            printf("x = %d\n",x);
            break;
        case 1:
            printf("x = %d\n",x);
            break;
        case 2:
            printf("x = %d\n",x);
            break;
        case 3:
            printf("x = %d\n",x);
            break;
        default:
            printf("This is the default case.\n");
            break;
    }
}