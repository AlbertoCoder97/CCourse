#include <stdlib.h>
#include <string.h>

int main()
{
    return 0;
}

char **stringGen(char **p, int n, int len)
{
    char chars[] = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/,.-+=<>:";

    srand(getpid());
    for(int i = 0; i < n; i++)
    {
        //Declare a random size for a string.
        int sz = rand()%len+1;

        //Reserve memory for that specific string length
        if(!(p[i]=malloc(sz+1)))
        {
            return NULL;
        }
        //Initialize memory at 0.
        bzero(p[i], sz+1);
        //Generate random string and store in that memory section that was just initialized at 0.
        for(int j=0; j < sz; j++)
        {
            p[i][j] = chars[rand()%sizeof(chars)-1];
        }
    }
    return p;
}
