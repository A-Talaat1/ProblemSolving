#include <stdlib.h>
#include <stdio.h>

int *SumArr(int *arr, int size)
{
    int *res = (int *) malloc((sizeof(int) * 2));
    res = NULL;

    int *left = arr, *right = arr+(size-1);

    while (left < right)
    {
        if (((*left) + (*right)) > 32)
        {
            --right;
        }
        else if (((*left) + (*right)) < 32)
        {
            ++left;
        }
        else
        {
            res[0] = *left;
            res[1] = *right;
            break;
        }
        
    }
    free(res);
    return res;
}

int arr[] = {2,7,11,15,17,28,31};

int main()
{
    int *res = SumArr(arr, (sizeof(arr)/sizeof(int)));

    if (res == NULL)
    {
        printf("ERROR");
    }
    else
    {
        for (int i = 0; i < 2; i++)
    {
        printf("%d\n", res[i]);
    }
    
    }
    

    
    return 0;
}
