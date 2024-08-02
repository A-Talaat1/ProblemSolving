#include <stdio.h>
#include <string.h>

// Function to find the length of the longest common subsequence of two strings
int longestCommonSubsequence(char* strip1, char* strip2) {
    // Get the lengths of the input strings
    int m = strlen(strip1);
    int n = strlen(strip2);
    
    // Create a 2D array to store the lengths of LCS
    int L[m + 1][n + 1];
    
    // Build the LCS table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                // If either string is empty, LCS length is 0
                L[i][j] = 0;
            } else if (strip1[i - 1] == strip2[j - 1]) {
                // If characters match, take the diagonal value and add 1
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                // If characters do not match, take the maximum value from left or top cell
                L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    
    // L[m][n] contains the length of LCS for strip1[0..m-1] and strip2[0..n-1]
    return L[m][n];
}

int main() {
    char strip1[] = "AGGTAB";
    char strip2[] = "GXTXAYB";
    // Print the length of the longest common subsequence
    printf("Length of LCS is %d\n", longestCommonSubsequence(strip1, strip2));
    return 0;
}
