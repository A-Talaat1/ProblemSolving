#include <stdio.h>
#include <string.h>

void incrementBinaryString(char* binaryStr)
{
    int len = strlen(binaryStr);
    int carry = 1;  // Initially we need to add 1

    // Start from the end of the string and move backwards
    for (int i = len - 1; i >= 0; i--)
    {
        if (binaryStr[i] == '1' && carry == 1)
        {
            binaryStr[i] = '0';  // 1 + 1 = 0 with a carry of 1
        }
        else if (binaryStr[i] == '0' && carry == 1)
        {
            binaryStr[i] = '1';  // 0 + 1 = 1 with no carry
            carry = 0;
        }
    }

    // If carry is still 1, it means we need to add a '1' at the beginning
    if (carry == 1)
    {
        // Shift all characters to the right by 1 position
        for (int i = len; i >= 0; i--)
        {
            binaryStr[i+1] = binaryStr[i];
        }
        binaryStr[0] = '1';  // Add '1' at the beginning
        binaryStr[len+1] = '\0';  // Null terminate the string
    }
}

int main()
{
    char binaryString[100] = "1011";  // Note: Ensure sufficient space for potential carry overflow
    incrementBinaryString(binaryString);
    printf("Incremented Binary String: %s\n", binaryString);
    return 0;
}
