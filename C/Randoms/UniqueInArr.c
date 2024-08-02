#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*Repeated numbers must occur even number of times*/
/*O(n)*/
int UniqueInArr_1(int *arr, int size)
{
    int res = 0;
    for(int counter = 0; counter < size; ++counter)
    {
        res ^= arr[counter];
    }

    return res;
}

/*O(n2)*/
int UniqueInArr_2(int *arr, int size)
{
    int counter1 = 0, counter2 = 0, OccurCounter = 0, Unique = -1;

    for(counter1 = 0; counter1<size; ++counter1)
    {
        OccurCounter = 0;

        for(counter2 = 0; counter2<size; ++counter2)
        {
            if ((counter1 != counter2) && (arr[counter1] == arr[counter2]))
            {
                ++OccurCounter;
            }
            
        }
        if (!OccurCounter)
        {
            Unique = arr[counter1];
        }
        
    }

    return Unique;

}

/*O(Max)*/
int UniqueInArr_3(int *arr, int size)
{
    int counter1 = 0;
    int Unique = -1;
    int Max = INT_MIN;

    for(counter1 = 0; counter1<size; ++counter1)
    {
        if (arr[counter1] > Max)
        {
            Max = arr[counter1];
        }
        
    }

    int *FreqArr = (int *) calloc(Max+1, sizeof(int));
    
    for(counter1 = 0; counter1<size; ++counter1)
    {
        ++FreqArr[arr[counter1]];
    }

    for(counter1 = 0; counter1<Max; ++counter1)
    {
        if (1 == FreqArr[counter1])
        {
            Unique = counter1; 
        }
        
    }
    free(FreqArr);
    return Unique;
}

int main()
{
    int arr[] = {1,2,1,1,2,5,6,7,7,7,6};

    printf("%d", UniqueInArr_3(arr, 11));
    return 0;
}