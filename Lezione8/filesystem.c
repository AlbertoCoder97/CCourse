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
File descriptors are objects that are available per-process. 
There is a limited amount of files that you can open via syscalls as the OS stores an array of 
file descriptors to avoid opening billions of files. This array of file descriptors is shared between
all processes, so if one process "consumes" the whole array, other processes can't open more files. */
void fdescriptorExample()
{
    //open and create return an integer that is the code returned after the open function. 0 when successfull.
    //open method parameters
    //When open returns an integer, the first LEGAL integer that returns is 3 as fd 0,1 and 2 are
    //created by the system. 0 is stdin, 1 is stdout and 2 is stderror.
    int open(const char *path, int oflag, mode_t mode);

    //S_IRUSR = readable by user, S_IWUSR = writable by user, S_IRGRP = readable by group.
    //The second option is the permissions of the file. Like 777 in Linux etc...
    int fd = open("/path/to/file", O_RDWR, S_IRUSR | S_IWUSR);

    //creat() is equivalent to open() with flags equal to O_CREAT|O_WRONLY|O_TRUNC.
    //If the file doesn't exist, it creates it.
    int creat(const char *pathname, mode_t mode);
    //S_IRUSR = readable by user, S_IWUSR = writable by user, S_IRGRP = readable by group.
    //The second option is the permissions of the file. Like 777 in Linux etc...
    //This systemcall is atomic. It was used to sync processes. Because you can't create a file
    //if the file already exists (used for semaphores).
    fd = creat("./newfile", S_IRUSR | S_IWUSR | S_IRGRP);

    //If you open a file twice, you get two different file descriptors. When you do this, you get two entities
    //in the kernel. They are two different objects.
    //There is another system call called dup which duplicates the file descriptor returning a new file
    //descriptor. When using dup, you only have one entity in the kernel.
    //dup2 is a similar system call that duplicates a file descriptor into another. When you write you
    //write in filedescriptor 1 (default descriptor), if you read you read from filedescriptor 0 (default)
    //fork() does the same of dup()
}

/* Read and Write from a file */
/* After getting the file descriptor with open/creat, you can use the read and write syscalls. */
void readAndWriteFile()
{
    //the first parameter is the file descriptor
    //the second parameter is the buffer where you want to read the data
    //the third parameters indicates the amount of bytes you wanna read.
    /* Read process: 
    * 1 - call the read passing the file descriptor
    * 2 - verify the mode -> vnode (virtual copy of the inode) -> get the rw-lock -> then you can read. 
    * 3 - read returns -> unlocks -> advance the offset -> return the number of bytes read.
    * If page is not in memory -> page fault.*/
    ssize_t read(int fd, void *buf, size_t count);

    //write is the same.
    //for the second parameter you need to put the constant because writing doesn't change the content of the buffer.
    //Make sure when you write strings to a file, remember to pass the length of the string +1
    //as there is also the \0 character to indicate string's end.
    /* Write process:
    * 1 - Write is cached before writing on disk. May increase the file size and may require the allocation
    * of data blocks.
    * 2 - Read the entire block -> Write relevant data -> write back all the block. 
    * */
    ssize_t write(int fd, const void *buf, size_t count);

    /* Everytime you read or write on the same file, you advance the file pointer. 
    If you read 1k you read the first kb, if you read again 1k you read from 1001 byte to 2k.
    It is possible to move the file pointer to read/write from an arbitrary point using 
    the syscall lseek*/
    
    //the first parameter is the file descriptor.
    //the second parameter says how much you wanna move.
    //the third parameter indicates where you want to start to add the offset.
    off_t lseek(int fd, off_t offset, int whence);

    //When creating a file, if you offset the beginning of a new file, it will make the file
    //as large as the offset. So if you offset 1G, the file will be 1G big.

    //After you're done writing/reading ALWAYS close the file.
    //close takes the filedescriptor as parameter. Once you close the file, you free the
    //file descriptor number!
    int close(int fd);

    //You can do multiple I/O operations at the same time using the iovec structure.
    //They aren't really used often.
}

