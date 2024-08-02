#include <stdio.h>
#include <limits.h>

// Function to find the maximum sum of a contiguous subarray
long find_max_sum(int* arr, int length)
{
    long max_sum = LONG_MIN;  // Initialize to the smallest possible value
    long current_sum = 0;     // Initialize current sum to zero

    for (int i = 0; i < length; i++) {
        current_sum += arr[i];  // Add current element to current_sum
        
        if (current_sum > max_sum)
        {
            max_sum = current_sum;  // Update max_sum if current_sum is greater
        }

        if (current_sum < 0)
        {
            current_sum = 0;  // Reset current_sum if it becomes negative
        }
    }

    return max_sum;  // Return the maximum sum found
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    long max_sum = find_max_sum(arr, length);
    
    printf("The maximum sum of a contiguous subarray is %ld\n", max_sum);
    
    return 0;
}
