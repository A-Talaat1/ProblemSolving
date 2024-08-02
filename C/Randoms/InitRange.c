#include <stdlib.h>
#include <stdio.h>

int *init_range(int length)
{
    int *arr = (int*) calloc(length, sizeof(length));
    int counter = 0;
    
    for(counter=0; counter<length; ++counter)
    {
        arr[counter] = counter;
    }

    return arr;
}

/*
int *init_range(int length)
{
    int *arr = (int*) calloc(length, sizeof(length));
    
    while (length)
    {
        arr[length-1] = length-1;
        --length; 
    }
    

    return arr;
}
*/

int main()
{
    int *range = init_range(6);
    for(int i=0; i<6;i++)
        printf("%d", range[i]);

    return 0;
}