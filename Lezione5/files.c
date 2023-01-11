#include "files.h"

/* By default there are 3 files that are always opened by the OS.
They're called stdin, stout and stderr. 
There is no need to open and close the standard streams but if
you want to explicitly do it, you can. */

/* Categories of I/O Functions:
* - File Open/Close
* - Formatted Input/Output
* - Character Input/Output
* - Line Input/Output
* - Block Input/Output
* - File Positioning
* - System File Operations
* - File Status
*/
int main()
{
    /* The FILE type is defined in stdio.h */
    //FILE* spData
    /*fopen is used to open a file and takes in input
    * the file name/path and the mode (w = write) and you get 
    * returned a pointer.
    */
    //spData = fopen("MYDATA.DAT", "w");
    
    /* if you don't want to mess with the stderr file,
    * you can use the perror function that takes a string
    * and it prints the string you passed and the content
    * of stderr */

    /* Once you get the FILE pointer you can use the file.
    * You can open the files in read mode (r), write mode(w) and
    * append mode (a).
    */
    /* If you open in w-mode the pointer points at the
    beginning of the file and you write and then it
    TRUNCATES the rest of the file with anything you've
    NOT written. */

    /* If you open the file in append, you position at the
    * end of the file and you just add data. */

   /* You must always close a file once finished working on it
   * as processes can only open a limited amount of files. */

    FILE* spTemps;
    if((spTemps = fopen("TEMPS.DAT", "r")) == NULL)
    {
        perror("ERROR opening TEMPS.DAT");
        return 100;
    }else{
        printf("File opened!\n");
    }

    if(fclose(spTemps) == EOF)
    {
        perror("ERROR closing TEMPS.DAT");
        return 102;
    }
    return 0;
}