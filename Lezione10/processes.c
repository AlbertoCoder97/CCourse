/* UNIX Processes */
/* UNIX Processes are "born" thorugh fork() from a process called "init". 
* A process can be killed volountarily by executing an exit() method or killed by the system 
* on errors/fault or by the user or by parent processes. 
* Some reasons about why a process can be killed are:
* Time Limit exceeded, Memory unavailable, Bounds violation, Arithmetic errors or timer overrun.
* The default limit are defined by ulimit -a in UNIX systems. 
* Other reasons might be invalid instructions, execution of privileged instruction in user mode, 
* the parent killing it or a request by another process to kill that specific process. */


/* Processes Statuses */
/* A process can be in the following states:
* - New
* - Ready (Ready to be dispatched and when it happens, it goes in running state)
* - Ready,suspend 
* - Running (Executes steps and after a bit the scheduler puts it back to ready to execute other processes)
* - Blocked (The process is waiting for an event to occur from the OS. Once the event happens, it goes back to ready)
* - Blocked, suspend 
* - Exit
* */

/* What happens when a process creates a new process */
/* 1 - It assigns a unique PID.
* 2 - Allocates space for the process. 
* 3 - Initialize process control blocks.
* 3 - Sets up appropriate linkages, like add new process to linked list used for scheduling queue or
* maintain an accounting file. */

/* When to Switch a Process */
/* The scheduler switches process when one of these events occurr: 
* 1 - Interrupts (like clock or I/O interrupts)
* 2 - Memory fault (memory page is not mapped)
* 3 - Trap (software interrupt due to an error that occurred) - Can cause a process to be moved to Exit state.
* 4 - System call like open()
*/


/* Process Context */
/* 1 - User address space: code, data, stack, shared memory regions.
*   - The code is the program that is executing
*   - We can have multiple instances of the same program but with different data.
*   - The stack contains the call stack, return addresses etc..
*   - When you have virtual memory, processes can't share data through memory directly so
*   - it is possible to request to the O.S to reserve a certain memory address range for the processes.
* 2 - Control information: u area, proc, kernel stack, addr. trans. map 
* 3 - Credentials: UID & GID. 
*   - Each process is capable to do something based on their credentials and their user permissions. 
*   - If you start a process with a certain user, then the process will have that user's permissions.
* 4 - Environment variables that are inherited from the parent. 
* 5 - Hardware context (in PCB of u area):
*   - PC, SP, PSW, MMR, FPU.
*/

/* User Credentials */
/* Each process has the following credentials:
* 1 - User ID and Group ID. The Superuser (like root) has UID and GID = 0
*   - If you use UID and GID = 0, you allow the process to do everything as it is a superuser.
* 2 - Real IDs: login, send signals.
*   - The real ID is the ID that a process gets when you login in a system for example.
* 3 - Effective IDs
*   - Effective IDs are used to allow certain process to execute privileged operations like
*   - file creation, password changes etc..
* 4 - exec()
*   - This system calls starts executing a new program setting the effective ID of the owner of that file
*   - if the bits SUID/SGID are set. Similarly to the flags used for files.
*/

/* System calls to know who's who */
/* 
* 1 - int getuid() returns the userid
* 2 - int getgid() returns the group id
* 3 - int geteuid() returns the effective userid
* 4 - int getegid() returns the effective groupid
*/

/* Mode, Space and Context */
/* Some system resources are critical and must be protected and are managed by the OS.
* 1 - Virtual memory
*   - VM Space
*   - Address Translation Maps
*   - Memory Management Unit
* 2 - Kernel mode
*   - This is the privileged mode and can use privileged instruction/functions
* 3 - User mode
*   - Less privileged and requires support from the processor.
*/

/* Kernel Data */
/* On one system there is only one instance of a kernel.
* You can have multiple processes but still, only one kernel. 
* You have Global Data Structures and Per-Process structures.
* When you call a system call, the process changes from user mode to kernel mode. 
*/

/* Kernel's Context */
/* The context must be re-entrant. It means that several processes may be involved in 
* kernel activities at the same time. 
The execution context can be a Process or System process. */

/* Process Context 
* User Mode: execute application user code, accesses process space only.
* If a system call is called by the process, then it goes to kernel mode and can access
* both process and system space. 
* 
* System Context 
* User mode: not allowed.
* Kernel mode interrupts, system tasks can access system space only. 
*/

#include <stdio.h>
#include <unistd.h>

void who();

int main()
{
    who();
    return 0;
}
//If you change the ownership of the .out file, it will still print the ids of the user that executes the file
//If you chmod 4755 processes.out it will run as ROOT and it will print EUID: 0!
void who()
{
    printf("UID: %d EUID: %d GID: %d EGID: %d\n",
    getuid(), geteuid(), getgid(), getegid());
}

