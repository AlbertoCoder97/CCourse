#include <stdio.h>
//The dirent header is NECESSARY in order to use systemcalls to open/read/close directories.
//It includes the structures used for directories.
#include <dirent.h>

//The stat header is necessary for the fstat function because it needs the definition of the 
//stat structure.
#include <sys/stat.h>

//This is needed to open files
#include <fcntl.h>

//To use the creat function you need this:
#include <sys/types.h>


int main()
{
    return 0;   
}

/* Directory Syscall */
/* Systemcalls are not library calls. Systemcalls are requests to the O.S. When you do a systemcall
you request something to the O.S and it uses superusers in order to execute operations. 
When you want to do something on a directory you need to use a systemcall to read/open a directory.*/


void directories()
{
    //This function allows you to open a directory.
    //You pass as argument the path of the directory which can be either full or relative.
    //It returns a pointer to the directory. On error, NULL is returned.
    int* dirp = opendir( "file.txt" /* char* filename */);

    //To read each entry in the directory you need readdir.
    //It returns a pointer to a dirent element that contains the Inode Number and the name of the file.
    int* direntp = readdir(dirp);

    //To go back to the first element in the directory you use the syscall rewinddir.
    //It returns nothing.
    rewinddir(dirp);

    //To close a directory you need to use the syscall closedir that takes a pointer to the directory.
    //which isdirp in this case.
    //It returns 0 on success, -1 on error.
    int status = closedir(dirp);
}

/* fstat */
/* fstat() is a systemcall that allows you to get informations about a file.
In the file attributes you can find several informations like file type, number of hard links
file size, devide ID, inode number, user and group IDs, timestamps, permissions and mode flags.
The FILENAME is NOT included in these information. You have the Inode Number but the filename
is in the directory data. 
Note: Hard Links use the InodeNumber of the file to create the link. */

void fstatExample()
{
    //it requires a filedescriptor and a pointer to a stat structure which is already defined
    //from C's standard libraries.
    //It returns 0 if it is successfull or a negative number in case of errors.
    int sts = fstat(fd, &statbuf);

    //stat is the same as fstat but you need to pass a const char* instead of a filedescriptor.
    int sts = stat("pippo.txt", &statbuf);
}

/* Accessing files in C */
/* In order to operate on files you need to use the "handle" or also called filedescriptor.
File descriptors are objects that are available per-process. */
void fdescriptorExample()
{
    //open method parameters
    int open(const char *path, int oflag, mode_t mode);

    //S_IRUSR = readable by user, S_IWUSR = writable by user, S_IRGRP = readable by group.
    //The second option is the permissions of the file. Like 777 in Linux etc...
    int fd = open("/path/to/file", O_RDWR, S_IRUSR | S_IWUSR);

    //creat() is equivalent to open() with flags equal to O_CREAT|O_WRONLY|O_TRUNC.
    int creat(const char *pathname, mode_t mode);
    //S_IRUSR = readable by user, S_IWUSR = writable by user, S_IRGRP = readable by group.
    //The second option is the permissions of the file. Like 777 in Linux etc...
    //This systemcall is atomic. It was used to sync processes.
    fd = creat("./newfile", S_IRUSR | S_IWUSR | S_IRGRP);
}

