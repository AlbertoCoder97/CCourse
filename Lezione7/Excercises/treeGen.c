#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "treeGen.h"

int main()
{
    return 0;
}

int insert(NODE **binary_tree, char value)
{
    NODE *tmp = NULL;
    int test;

    if(!(*binary_tree))
    {
        if(!(tmp=(NODE *)malloc(sizeof(NODE))))
        {
            //This prints the reason why malloc failed.
            perror("malloc");
            return -1;
        }

        tmp->left = tmp-> right = NULL;
        tmp->key = value;
        *binary_tree = tmp;
        return 0;
    }

    if(!(test=strcmp(value,(*binary_tree)->key)))
    {
        printf("%s is a duplicate\n", value);
        return 1;
    }
    if(test < 0)
    {
        insert(&(*binary_tree)->left, value);
    }
    else
    {
        insert(&(*binary_tree)->right, value);
    }

    return 0;
}