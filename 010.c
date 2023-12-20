#include <stdio.h>

int main() 
{
    int x, y, result; // Declare variables for two integers and their product

    // Prompt user for input and store in 'x'
    printf("\nInput the first integer: "); 
    scanf("%d", &x);

    // Prompt user for input and store in 'y'
    printf("\nInput the second integer: ");
    scanf("%d", &y);

    result = x * y; // Calculate the product of 'x' and 'y'

    // Print the product
    printf("Product of the above two integers = %d\n", result);
}
