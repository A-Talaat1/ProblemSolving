#include "StdTypes.h"
#include "stdlib.h"
#define SIZE_OF_CHAR 8

void *DecToBin(u8 Dec)
{
    u8 *bin = (u8*)malloc(SIZE_OF_CHAR * sizeof(u8));

    for(u8 counter = 0; counter < SIZE_OF_CHAR; ++counter)
    {
        bin[counter] = Dec>>counter & (0x01);
    }
    return bin;
}
/*
int main()
{
    u8 *res;
    res = DecToBin(7);
    
    for (u8 i = 0; i < 8; i++)
    {
        printf("%d\n",(u8)res[i]);
    }
    

    return 0;
}
*/