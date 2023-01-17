#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Unions have a syntax almost identical to structures. But there is a difference.
* All fields in a union share the SAME memory. Unions are not as used as structures. */

/* Unions are usually used for conversion. Example: Convert IP Address to long*/

typedef union 
{
    unsigned char chAddr[4];
    unsigned long numAddr;
} IP_ADDR;


int main()
{
    IP_ADDR addr;
    char* parser;

    char strAddr[16] = "153.18.8.105";

    parser = strtok(strAddr, ".");
    addr.chAddr[3] = strtol(parser, (char**)NULL, 10);

    for(int i = 2; i >= 0; i--)
    {
        parser = strtok(NULL, ".");
        addr.chAddr[i] = strtol(parser, (char**) NULL, 10);
    }

    printf("IP Decimal dot: %d.%d.%d.%d\n", addr.chAddr[3], addr.chAddr[2],addr.chAddr[1], addr.chAddr[0]);

    return 0;
}