#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MSGSIZE     16

/* Pipes */
/* 
* Pipes are a unidirectional FIFO unstructured data stream. 
* Pipes have two ends, one where data is written and one where data is read.
* The data in the pipe can be filled and the process can get suspended if
* pipe is full.
*/

/*
* You need to call the pipe(int[2] fileDescriptors) function. 
* As specified you need to pass two fileDescriptors, one for reading, 
* one for writing. 
*/

/*
* Pipes are used to pass information between processes that need to 
* communicate and they both open the same pipe.
* In order to have the same pipe open, you MUST share the fileDescriptors
* and to have that you MUST fork() a process otherwise you can't share
* the descriptors. */

/*
* You write to fileDesc[1] and you read from fileDesc[0], very similarly
* to standard file descriptors.
*/

/*
* Pipes have limited bufferspace and the value is system dependent.
* Un-named pipes can only be used between relative processes.
* Pipes are often used with dup()/dup2()
*/

/*
* In pipes you can write and read any type of data.
* You can read from the buffer any amount of bytes you like as long as it is
* a small amount. You can even read 1 char at the time.
*/

void simpleExample();
void secondExample();
void thirdExample();