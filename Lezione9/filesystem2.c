#include <stdio.h>

int main(int argc, char *argv[])
{
    return 0;
}

/* Link, Unlink, Rename syscall */
/* They all return 0 if successful or -1 in case of errors */
void exampleLinkUnlinkRename()
{
    //the link syscall creates a new HARD link to the specified file.
    int link(const char *oldpath, const char *newpath);

    //Unlinks a file and possibly deletes it.
    //If the hard link counter becomes 0, the file is deleted.
    int unlink (const char *pathname);

    //Renames a file, moving it between directories if required.
    int rename(const char *oldpath, const char *newpath);
}

/* Locking is needed to avoid file corruption and to avoid multiple processes to write/read from the same
* file at the same time. Some operations like creation or removal are atomical. 
* There are multiple types of locks: Advisory and mandatory Locks. Mandatory locks require kernel support
* and advisory locks protect from cooperative processes. */
void fileLocking()
{

}

/* Partitions & Logical Disks */
/* A partition is a portion of a physical disk drive. A logical disk is a storage abstraction composed
* even of multiple physical disks but is a linear sequence of fixed-sized, randomly accessible blocks.
* */


/* File System */
/* Once we have a device, you want to create a file system and there is a specific command for that.
* On UNIX systems the command is called mkfs that creates a file system on a devide. 
* A file system, to be accessible must be mounted on a mount point. The mount point (which is a directory)
* is then covered by the mounted file system. 
* You can mount a system file inside another system file. Note that you can't create loops with links. */


/* I/O Implementation in Unix */
/* UNIX has the concepts of Block and character devices. Block devices are devices that can be accessed 
* in blocks. A character device instead is a device where you can read one character after the other
* like a console, printer etc... Devices, both block and characters, in UNIX are seen as files. 
* Devices (both block and char devices) in UNIX systems are under /dev/. When you have multiple devices
* you can use the major and minor device number, where the major number is the entry to that specific
* driver (like an index in arrays), while the minor numbers that represent the disks on that drive. */