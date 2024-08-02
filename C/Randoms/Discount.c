#include <stdio.h>

typedef enum
{
    standard,
    seasonal,
    weight
} DiscountType;

double get_discounted_price(double cart_weight, double total_price, 
                            DiscountType discount_type)
{
    double discounted_price;
    // Waiting to be implemented
    switch (discount_type)
    {
    case standard:
        discounted_price = total_price - (total_price * (6.0/100.0));
        break;
    case seasonal:
        discounted_price = total_price - (total_price * (12.0/100.0));
        break;
    case weight:
        if(cart_weight <= 10)
        discounted_price = total_price - (total_price * (6.0/100.0));
        else
        discounted_price = total_price - (total_price * (18.0/100.0));
        break;

    default:
    discounted_price = -1;
        break;
    }
    return discounted_price;
}

#ifndef RunTests
int main()
{
    printf("%.2f", get_discounted_price(12, 100, weight));
    return 0;
}
#endif