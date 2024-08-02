#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef enum
{
    Max1 = 0,
    Max2,
    Max3,

} Max_t;

int *FindMax3(int *Arr, int size)
{
    int *res = (int *)calloc(3, sizeof(int));
    int counter;

    // Initialize the results array to the minimum integer value
    for (counter = 0; counter < 3; ++counter)
    {
        res[counter] = INT_MIN;
    }

    for (counter = 0; counter < size; ++counter) // res[0]   res[1]   res[2]
    {
        if (Arr[counter] > res[Max1])
        {
            res[Max3] = res[Max2];
            res[Max2] = res[Max1];
            res[Max1] = Arr[counter];
        }
        else if (Arr[counter] > res[Max2])
        {
            res[Max3] = res[Max2];
            res[Max2] = Arr[counter];
        }
        else if (Arr[counter] > res[Max3])
        {
            res[Max3] = Arr[counter];
        }
    }

    return res;
}

int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3, 75};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *max3 = FindMax3(arr, size);

    printf("The top three maximum elements are: %d, %d, and %d\n", max3[Max1], max3[Max2], max3[Max3]);

    free(max3);

    return 0;
}
