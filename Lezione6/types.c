/* You can create new types in C.*/

//typedef type(standard or derived) IDENTIFIER
//This means that now PIPPO is an INT type
typedef int PIPPO;

/* Structures - Very similar to objects */
/* You can declare structure in different ways. */

/* You can use structures as variables types in structures. */

/* If you don't use typedef to declare an instance of STUDENT
* you need to use struct STUDENT aStudent.
* To make it easier/like other objects, always use typedef struct*/
typedef struct STUDENT
{
    char id[10];
    char name[26];
    int gradePts;
};

struct STUDENT instanceStudent; //Instance of the STUDENT structure.

struct TAG
{
    int data;
};

struct
{
    int example;
} EXAMPLE;

typedef struct NAME 
{
    int a;
    int b;
};


int main()
{
    NAME alberto = {2,3};
    alberto.a; //gets the int a;
    alberto.b; //gets the int b;

    //you can make pointers to instances of a struct.
    SAMPLE sam1;
    SAMPLE* ptr;

    prt = &sam1;
    //When using pointers you need to use -> to access instances' variables.

    //You can create arrays of structures.
    
    return 0;
}