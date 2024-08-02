#include <stdio.h>
#include <stdlib.h>

int copy_bit(int src, int dst, int pos)
{
    char bit;

    bit = src<<pos & 1;

    dst &= ~(1<<pos);

    dst |= bit<<pos;

    return dst;
}


int main()
{
    printf("%d", copy_bit(7, 12, 3));
    return 0;
}