#include "arrays.h"

int main()
{
    //This is an array of 9 elements with index starting 0 to 8,
    int scores[9];
    int RollNum[30][4];

    //This is an array of 9 pointers to integer.
    //int * scores[9];

    //To declare a pointer to an array you need to put the pointer in brackets.
    //p is a pointer to an array of 4 elements (ignore the assignment to RollNum)
    int (*p)[4] = RollNum;

    //You can initialize an array without an explicit dimension like this:
    //int numbers[ ] = {1,2,3,4,5};

    //You can partially initialize an array and every element not specified, is 0.
    int numbers[5] = {3,7}; //3,7,0,0,0

    //You cannot copy an array using an assignment
    //array1 = array2 is ILLEGAL. It doesn't work.
    //To copy array elements you either use a loop or use the memcpy() function.

    //The name of the array is a pointer to the first element.
    int arr[10];
    //writing arr is the same as writing &a[0]
    //if you write sizeof(arr) it tells the size of the first element, not the size of the array.

    //Instead of declaring an enormous two-dimensional array in case you know that
    //each row has different amount of elements in order to not waste space
    //you can declare a vector of pointers to an int/one-dimensional array and loop
    //through the vector that indicates the row number and elements of each row
    //preserving some of space.

    int a[5] = {2,4,6,8,10};
    printf("%d %d\n", *a, a[0]);

    /* Given any pointer if you increment or decrement any pointer, you add
    * the size of the object pointer to the pointer. If p is a pointer p+1 is the
    * pointer to the second element regardless of the size of the element.*/

    return 0;
}