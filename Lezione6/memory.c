/* There are two elements in the program memory:
* main and function 
* The Data memory is divided in three regions:
* 1 - Global area where you have static variables.
* 2 - stack is where the automatic variables are allocated. 
* 3 - heap is the memory for arrays, variables etc... */

/* In C heap management is EXPLICIT. There is no garbage collection like other
* languages. If you allocate 1MB of memory, you need to clean the 1MB memory. */

/* There are multiple functions that allow us to allocate memory: 
* 1 - malloc() reserves the memory big enough to store our object. 
* 2 - calloc() is quite similar to malloc() but calloc ALSO INITIALIZES THE MEMORY.
* 3 - realloc() reallocates memory when buffer is small/too big.
* 4 - free - THIS IS EXTREMELY IMPORTANT. It frees the memory allocated with malloc().
* It's needed to free memory areas allocated with malloc to avoid filling memory/memory leaks.*/

//When using malloc you need to cast the type in order to correctly indicate the type of
//what malloc returns: pointer = (type*) malloc();

/* malloc() is a library function in C, not a syscall. You should check malloc's return value.
* When malloc fails, it returns NULL. */

/* After using free you STILL have the pointer but the area might be used for something else.
* Tip: after calling free(ptr) use ptr = NULL in this way you null the pointer. */

/* After free you can reuse malloc to reallocate the memory freed since freed memory still
* "belongs" to the process if it's still alive. */

/* TIP: Instead of using calloc() use this:
* p = malloc(SIZE)
* bzero(p, SIZE) where bzero is a function that sets 0 in the memory designated initializing
* the memory. */

//ALWAYS CLEAR POINTERS

/* To save space when creating two-dimensional arrays is to manually create the second dimension
* by allocating exactly the memory needed for each row in order to avoid wasting columns. 
* table = (int **)calloc(rownum+1, sizeof(int*))
* table now is a pointer to pointers of int. 
* table[0] = (int*)calloc(4,sizeof(int)) etc... 
* In this way table[i] contains pointers to ints and table itself contains pointers to pointers.*/

int main()
{
    /* A - Static Memory Allocation */
    int x = 0;
    int array[3] = 0;

    /* B - Dynamic Memory Allocation */
    int * x;
    //x = malloc(); - Do not decomment to avoid breaking everything.
    //array = calloc(); - This also initializes memory.

    return 0;
}