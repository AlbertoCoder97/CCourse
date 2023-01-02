#include <stdio.h>

//Standard libraries needed for socket's connection
#include <sys/types.h> 
#include <sys/socket.h>

/*
* socket() used to create a connection takes three parameters:
* AF_INET is the domain type and it corresponds to IPV4. 
* SOCK_STREAM is the socket's type which corresponds to TCP/UDP
* PROTOCOL defines the protocol we use for communication, we use IP.
*/
#define DOMAIN AF_INET
#define SOCKET_TYPE SOCK_STREAM
#define PROTOCOL 0

#define BUFFER_SIZE 255
#define PORT 8080