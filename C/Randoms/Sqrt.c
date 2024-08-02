#include <stdio.h>

double taylor_series_sqrt(double num) {
    if (num < 0) {
        return -1; // Square root of a negative number is not defined
    }
    if (num == 0 || num == 1) {
        return num; // Square root of 0 is 0, square root of 1 is 1
    }

    double x = num;
    double sum = 1.0; // Initialize sum of series
    double term = (x - 1) / (x + 1);
    double term_squared = term * term;
    double factor = term;

    for (int i = 1; i < 100; i += 2) {
        sum += (factor / i);
        factor *= term_squared;
    }

    return 2 * sum;
}

int main() {
    double num = 25.0;
    printf("The square root of %.2f using Taylor series expansion is %.10f\n", num, taylor_series_sqrt(num));
    return 0;
}
