/* The syscall() Interface */
/* syscall() gets some parameters and one of them is what the process wants from the kernell.
* While the process is executing, when syscall() is called, then it switches to kernel mode
* in Process Context! 
* Therefore it can copy arguments, save hardware context on the kernel stack.
* Use system call number to index dispatch vector that allows you to know how many syscalls 
* are to be executed. 
* Return results in registers, restore user mode. 
*/

/* The syscall interface is available on 64-bit x86 Linux machine. 
* It is a request to the kernel to do something. 
* Syscall number should be in register "rax".
* Assembly example of fork() which is the ID 57:
* mov rax,57;
* syscall;
* ret;
*/

/* New Processes and Programs */
void fork()
{
    //This creates a new process, returns 0 to the child and the PID to the parent.
    //To check which is the parent and who is the child, just check the return value.
    //The best way to handle PIDs is using the pid_t structure of <sys/types.h>
    int fork();
    //Executes a new program. Takes in input the path of a program.
    //The * is because there are multiple versions of exec();
    int exec*();
    //The wait system calls waits for the return code of the children processes.
    //Allowing the child to terminate correctly and then the parent as well.
    wait();
}

/* Executing programs in child fork */
void executeProg()
{
    if((ChildPid = fork()) == 0)
    {
        /* child code */
        if(execve("new proigram", ...) < 0)
        {
            perror("execve failed.");
            exit(-1);
        }
    } else if (ChildPid < 0)
    {
        perror("fork failed.");
        exit(-1);
    }

    /* Parent code continues here */
}

/* Zombie processes */
/* Upon termination, kernel holds processes structure. These are zombire processes. 
* wait() frees the process, but must be called by the parent or the init process. 
* This happens when a child dies before the parent, or the parent doesn't wait for all the children.
*/