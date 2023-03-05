#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* 
* Named Pipes can be shared between different processes. 
* They have an iNode so theyt can be identified by their access point path/filename.
* in order to create a named pipe you need to use: mkfifo(char *path, mode_t mode);
*/

/*
* In general pipes have been replaced by sockets as pipes are relevant only
* to a single system. Also named pipes do not allow to do BOTH reading and
* writing at the same time.
*/

/*
* As named pipes are persistent, once a program that uses a named pipe
* terminates, the pipe remains in the system so any other program can open
* that same named pipe without any errors.
* Note that when calling the mkfifo you can check for the error of ALREADY EXIST.
*/

/*
* If you do ll in the folder where a pipe is, instead of the d flag, you get p.
*/

/*
* In order to have bi-directional pipes, you need two pipes.
*/