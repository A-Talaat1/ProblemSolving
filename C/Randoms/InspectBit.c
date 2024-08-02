#include <stdlib.h>
#include <stdio.h>

/*
int inspect_bits(unsigned int number)
{
    // Waiting to be implemented
    int counter = 0;
    const int NumOfBits = sizeof(number) * 8;
    int bit[NumOfBits];

    for(counter = 0; counter < NumOfBits; ++counter)
    {    
        bit[counter]= (number >> counter) & 1 ;
    }
    
    for(counter = 0; counter < NumOfBits-1; ++counter)
    {

    if (bit[counter] == 1 && bit[counter+1] == 1)
    {
        return 1;
    }

    }
    
    return 0;
}

*/

int inspect_bits(unsigned int number)
{
    int counter = 0;
    const int NumOfBits = sizeof(number) * 8;
    int ConsecutiveFlag = 0;

    for(counter = 0; counter < NumOfBits-1; ++counter)
    {
        if ( (number & (1<<counter)) && (number & (1<<(counter+1))) )
        {
            ConsecutiveFlag = 1;
        }
    }
    return ConsecutiveFlag;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(13));
}
#endif