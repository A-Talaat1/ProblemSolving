#include <stdio.h>

double calculate_final_speed(double initialSpeed, int inclinations[], int array_length) 
{
    // Waiting to be implemented
    int counter = 0;

    for(counter = 0; counter < array_length; ++counter)
    {
        if (inclinations[counter] < 0)
        {
            initialSpeed += (inclinations[counter] * (-1));
        }
        else
        {
            initialSpeed -= (inclinations[counter]);
        }
    }
    if (initialSpeed <= 0)
    {
        return 0;
    }
    
    return initialSpeed;
}

#ifndef RunTests
int main() 
{
    int inclinations[] = { 0, 30, 0, -45, 0 };
    int array_length = sizeof(inclinations) / sizeof(inclinations[0]);
    printf("%.2f\n", calculate_final_speed(60, inclinations, array_length));
    return 0;
}
#endif
