/* 
* Write a program in C to create and store information in a text file 
* Input a sentence for the file : This is the content of the file test.txt.
* Expected Output: The file <filename> created successfully. 
*/

#include "ex1.h"

char* PATH = "./txt/";
char* command = "create";

void main(int argc, char **argv[])
{
    if(argc < 3)
    {
        printf("Usage: create <file>\n");
        exit(1);
    }

    printf("argv[1] = %s\n", argv[1]);
    if(strcmp(argv[1], command) == 0)
    {
        printf("secondo if\n");
        printf("Usage: create <file>\n");
        exit(1);
    }

    char* filename;
    strcat(filename, PATH);
    strcat(filename, argv[1]);

    printf("This is the final string: %s\n", filename);
    
    /*
    if(creat(filename, S_IRUSR | S_IWUSR ) < 0)
    {
        perror("Error during file creation");
    }else
    {
        printf("File created!\n");
    }
    */

    exit(0);
}
