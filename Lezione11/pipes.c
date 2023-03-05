#include "pipes.h"

char *msg1 = "hello #1";
char *msg2 = "hello #2";
char *msg3 = "hello #3";



int main(int argc, char* argv[])
{
    //printf("First Example\n");
    //simpleExample();
    //printf("Second Example\n");
    //secondExample();
    printf("Third Example\n");
    thirdExample();
    return 0;
}

void simpleExample()
{
    char inbuf[MSGSIZE];

    int p[2], j;

    /* open pipe */
    if(pipe(p) == -1)
    {
        perror("pipe call error");
        exit(1);
    }

    /* write down pipe */
    strcpy(inbuf, msg1);
    write(p[1], inbuf, sizeof(inbuf));
    strcpy(inbuf, msg2);
    write(p[1], inbuf, sizeof(inbuf));
    strcpy(inbuf, msg3);
    write(p[1], inbuf, sizeof(inbuf));

    /* read pipe */
    for(int i = 0; i < 3; i++)
    {
        read(p[0], inbuf, sizeof(inbuf));
        printf("%s\n", inbuf);
    }
}

void secondExample()
{
    char inbuf[MSGSIZE];

    int p[2], j;

    pid_t pid;

    /* open pipe */
    if(pipe(p) == -1)
    {
        perror("pipe call error");
        exit(1);
    }

    switch(pid = fork())
    {
        case -1:
            perror("error: fork call");
            exit(2);
        
        case 0: /* if child then write down pipe */
            //This is not necessary but it is good habit to close the read fileDescriptor of the child pipe
            //as the reading is done by the parent and not by the child.
            close(p[0]);
            strcpy(inbuf, msg1);
            printf("Child: Writing message 1 in pipe buffer.\n");
            write(p[1], inbuf, sizeof(inbuf));
            strcpy(inbuf, msg2);
            printf("Child: Writing message 2 in pipe buffer.\n");
            write(p[1], inbuf, sizeof(inbuf));
            strcpy(inbuf, msg3);
            printf("Child: Writing message 3 in pipe buffer.\n");
            write(p[1], inbuf, sizeof(inbuf));
            break;

        default: /* parent section */
            //Closing write-end of the pipe as parent needs to read only.
            close(p[1]);
            for(int i = 0; i < 3; i++)
            {
                read(p[0], inbuf, MSGSIZE);
                printf("Parent: %s\n", inbuf);
            }
            wait(NULL);
    }
}

void thirdExample()
{
    //What happens if you dup something that is closed?
    char inbuf[MSGSIZE];

    int p[2], i;

    pid_t pid;

    /* open pipe */
    if(pipe(p) == -1)
    {
        perror("pipe call error");
        exit(1);
    }

    switch(pid = fork())
    {
        case -1:
            perror("fork");
            exit(2);
        case 0:
            close(p[0]);
            //Duplicating fd p[1] to std fd 1, so anything that i write
            //on fd[1] it is sent to stdout!!!!
            if(dup2(p[1], 1) == -1)
            {
                perror("dup2 failed");
                exit(1);
            }
            close(p[1]);
            printf("Child says: %s\n", msg1);
            printf("Child says: %s\n", msg2);
            printf("Child says: %s\n", msg3);
        
        default:
            close(p[1]);
            if(dup2(p[0], 0) == -1)
            {
                perror("dup2 failed");
                exit(1);
            }

            while(i = read(0, inbuf, sizeof(inbuf) -1))
            {
                inbuf[i]='\0';
                printf("Parent: <%s>\n", inbuf);
            }
    }
    wait(NULL);
}
