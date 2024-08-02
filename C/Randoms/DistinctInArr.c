#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int *DistinctInArr(int *arr, int size, int *ReturnSize)
{
    int counter = 0;
    int Max = INT_MIN;
    int ResCounter = 0;

    for(counter = 0; counter<size; ++counter)
    {
        if (arr[counter] > Max)
        {
            Max = arr[counter];
        }
        
    }

    int *Res = (int *) calloc(size, sizeof(int));
    int *FreqArr = (int *) calloc(Max+1, sizeof(int));

    for(counter = 0; counter<size; ++counter)
    {
        if (!FreqArr[arr[counter]])
        {
            Res[ResCounter++] = arr[counter];
            ++FreqArr[arr[counter]];
        }
        
    }

    *ReturnSize = ResCounter;
    Res = realloc(Res, ResCounter * sizeof(int));

    free(FreqArr);

    return Res;

}

int main()
{
    int counter = 0;
    int size;
    int arr[] = {1,1,2,3,4,4,3,2,0,2};
    int *res = DistinctInArr(arr, 10, &size);

    for(counter = 0; counter<size; ++counter)
    {
        printf("%d\n", res[counter]);
    }
    return 0;
}