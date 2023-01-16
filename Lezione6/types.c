/* You can create new types in C.*/

//typedef type(standard or derived) IDENTIFIER
//This means that now PIPPO is an INT type
typedef int PIPPO;

/* Structures - Very similar to objects */
/* You can declare structure in different ways. */
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

struct NAME 
{
    int a;
    int b;
} instance; //Instance is an instance of NAME.


int main()
{
    return 0;
}