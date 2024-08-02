/*
If you have array of 101 element and all numbers are from 1 : 100 are there but not sorted and there is one is repeated how to
find it?
*/

#include "StdTypes.h"


int FindRepeatedNumInArray(int *arr)
{
    int num=-1;

    for (u8 i = 0; i < 101; i++)
    {
        for (u8 j = 0; j < 101; j++)
        {
            if (arr[i] == arr[j])
            {
                num = i;
            }
        }
    }
    return arr[num];
}

int FindRepeatedNumInArray_2(int *arr)
{
    int visited[101] = {0};

    for (u8 i = 0; i < 101; i++)
    {
        if (visited[arr[i]])//if visited
        {
            return arr[i];
        }

        visited[arr[i]] = 1;
        
    }
    return -1;
}

int FindRepeatedNumInArray_3(int *arr)
{
    int i=0;
    int visited[101] = {0};

    while (!visited[arr[i]])
    {
        visited[arr[i]] = 1;
        i++;
    }

    return arr[i];
}

/*

int arr[101] = {
    17, 56, 43, 29, 99, 85, 61, 11, 74, 82,
    32, 9, 48, 36, 93, 27, 20, 68, 7, 65,
    16, 57, 22, 38, 75, 6, 91, 44, 35, 19,
    49, 26, 60, 53, 72, 13, 95, 78, 30, 69,
    70, 39, 2, 50, 10, 84, 8, 55, 63, 71,
    28, 94, 83, 79, 34, 46, 59, 90, 64, 76,
    5, 89, 97, 66, 33, 18, 81, 12, 3, 47,
    45, 4, 87, 25, 1, 58, 23, 21, 62, 31,
    86, 40, 41, 73, 15, 96, 14, 88, 80, 24,
    54, 98, 77, 67, 42, 92, 51, 52, 37, 0,
    15
};

int main()
{
    int res = FindRepeatedNumInArray(arr);
    printf("%d\n", res); 
    return 0;
}
*/