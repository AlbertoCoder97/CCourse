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
* 3 - Trap (sw interrupt due to an error that occurred)
* 4 - System call like open()
*/