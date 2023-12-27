#include <stdio.h>
int main() {
    int p, q, r, s; // Declare variables for four integers

    // Prompt user for the first integer and store in 'p'
    printf("\nInput the first integer: "); 
    scanf("%d", &p);

    // Prompt user for the second integer and store in 'q'
    printf("\nInput the second integer: ");
    scanf("%d", &q);

    // Prompt user for the third integer and store in 'r'
    printf("\nInput the third integer: ");
    scanf("%d", &r);

    // Prompt user for the fourth integer and store in 's'
    printf("\nInput the fourth integer: ");
    scanf("%d", &s);

    // Check conditions for correctness
    if((q > r) && (s > p) && ((r+s) > (p+q)) && (r > 0) && (s > 0) && (p%2 == 0))
    {
        printf("\nCorrect values\n");
    } 
    else {
        printf("\nWrong values\n");
    }

    return 0;
}

