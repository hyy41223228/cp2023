#include <stdio.h>
int main() 
{
    int x, y, sum; // Declare variables for two integers and their sum

    // Prompt user for input and store in 'x'
    printf("\nInput the first integer: "); 
    scanf("%d", &x);

    // Prompt user for input and store in 'y'
    printf("\nInput the second integer: ");
    scanf("%d", &y);

    sum = x + y; // Calculate the sum of 'x' and 'y'

    // Print the sum
    printf("\nSum of the above two integers = %d\n", sum);

    return 0; // Indicate successful execution
}

