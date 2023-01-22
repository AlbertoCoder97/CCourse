/* 
* Write a program in C to create and store information in a text file 
* Input a sentence for the file : This is the content of the file test.txt.
* Expected Output: The file <filename> created successfully. 
*/

#include "ex1.h"

/* When the process exits, these variables will be freed when the program exits. */
char* PATH = "./txt/";
char* command = "create";

void main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: create <file>\n");
        exit(1);
    }

    if(strcmp(argv[1], command) != 0)
    {
        printf("Usage: create <file>\n");
        exit(1);
    }

    char* fullPath = concatString(PATH, argv[2]);
    printf("This is the final string: %s\n", fullPath);
    
    
    if(creat(fullPath, S_IRUSR | S_IWUSR ) < 0)
    {
        perror("Error during file creation");
    }else
    {
        printf("File created!\n");
    }

    /* We need to free the memory allocated for fullPath */
    free(fullPath);

    exit(0);
}
