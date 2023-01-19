#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    char *name;
    int i;
    DIR *dirp;

    struct dirent *entp;

    if(argc < 2)
    {
        fprintf(stderr, "Usage\n\t%s <dir> ...\n", argv[0]);
        exit(1);
    }

    for(i = 1; i < argc; i++)
    {
        name = argv[i];
        printf("\n========= %s =========\n", name);
        if(!(dirp=opendir(name)))
        {
            perror("opendir");
            continue;
        }

        while(entp=readdir(dirp))
        {
            printf("-------------------------\n");
            printf("inode:\t%lx\toffset:\t%lx\n", entp->d_ino, entp->d);
            printf();
            printf();
            printf("-------------------------\n");
        }
    }

}