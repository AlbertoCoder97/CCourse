/* There are two elements in the program memory:
* main and function 
* The Data memory is divided in three regions:
* 1 - Global area where you have static variables.
* 2 - stack is where the automatic variables are allocated. 
* 3 - heap is the memory for arrays, variables etc... */

/* In C heap management is EXPLICIT. There is no garbage collection like other
* languages. If you allocate 1MB of memory, you need to clean the 1MB memory. */

/* There are multiple functions that allow us to allocate memory: 
* 1 - malloc() that initializes the memory big enough to store our object. 
* 2 - calloc() is quite similar to malloc()
* 3 - realloc() reallocates memory when buffer is small/too big.
* 4 - free - THIS IS EXTREMELY IMPORTANT. It frees the memory allocated with malloc().
* It's needed to free memory areas allocated with malloc to avoid filling memory/memory leaks.*/


int main()
{
    /* A - Static Memory Allocation*/
    int x = 0;
    int array[3] = 0;

    /* B - Dynamic Memory Allocation */
    int * x;
    //x = malloc(); - Do not decomment to avoid breaking everything.
    //array = calloc(); - This also initializes memory.

    return 0;
}