/**
 * Shared memory is a portion of memory that can be accessed by multiple processes.
 * Each process has its own Virtual Memory addresses but if we map a Shared Memory region
 * in both processes, they can share the same physical area. The virtual addresses in both processes
 * will be different but they will point to the same physical area.
 * Note that shared memory areas are limited by the O.S.
 * The fact that virtual pointers are different is the reason why you cannot use shared pointers 
 * to point to the same Shared Memory regions.
 * 
 * Shared memory segments can be passed down to child processes. First you need to associate
 * the shared memory to the parent process and then, after you fork() the child will inherit
 * that shared memory section.
 * Shared Memory segments do not get destroyed after exec() or exit() but they get detached from
 * the child process that dies.
 * 
 * To destroy shared memories and to see them, you have commands like ipcs, ipcrm like semaphores.
*/

/**
 * Shared Memory API consists of several functions that allow the process to use shared memory.
 * 
 * int shmget(key_t key, size_t size, int flag);
 * Returns the identifier of the shared memory segment associated with that key, similarly to
 * semaphores.
 * 
 * key value can be: IPC_PRIVATE or an int
 * size: size of shared area (in bytes)
 * flag: IPC_CREATE, permissions etc...
 * 
 * After you get the ID of the Shared Memory segment with shmget(); you need to attach the memory
 * segment to the process address space. This is done by using:
 * void* shmat(int shmid, void *shmaddr, int shmflag);
 * This function will return the pointer to the shared memory segment.
 * 
 * shmid is the return value of shmget
 * shmaddr is the DESIRED address, meaning you are requesting the system to map the shared memory
 * segment you're requesting to the specified address. This request, can fail so you usually see NULL in this parameter.
 * shmglag: SHM_READONLY, SHM_RND etc....
 * 
 * To detach the shared memory segment associated to a process you can use this function:
 * int shmdt(void *shmaddr);
 * 
 * Finally there is the control operation to remove the shared memory segment. This MUST be done
 * by at least one process. Usually it is common occurrence to destroy the shared memory segment
 * from the last process that exits. 
 * int shmctl(int shmid, int cmd, struct shmid_ds *buf);
 * This method performs the operation indicated by cmd on the shared memory segment identified by shmid.
 * 
 * cmd: IPC_RMID
 * bud: addresses of struct to hold information about segment.
 * 
 * The function ftok is a method that returns a key that can be correlated to a file name.
 * key_t ftok(char *pathname, int ndx);
 * 
 * pathname is the path of the file (which must be accessible by the process)
 * ndx are the 8 least significant bits
*/

/**
 * Shared memory must be explicitly removed using the IPC_RMID command parameter in the shmctl method.
 * The segment is then marked as removed but it will be destroyed only when the last process call shmdt();
 * 
 * Therefore it is common to create the segment on one process, map the shared memory on all processes
 * and then remove the segment on one process. This is done to avoid to leave unused segment (in case of crashes)
*/


#pragma once
#include <stdlib.h>
#include <stdio.h>