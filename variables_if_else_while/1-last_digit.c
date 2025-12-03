#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
*
*   OBJECTIVE: This program will assign a random number to the variable n 
*   each time it is executed. Complete the source code in order to 
*   print the last digit of the number stored in the variable n.
*
**/

int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;

    int d = n % 10;
    printf("Last digit of %d is %d and is ", n, d);

    if (d > 5)
    {
        printf("greater than 5");
    }
    else if (d < 6)
    {
        printf("less than 6 and not 0");
    }
    else
    {
        printf("0");
    }
    
	return (0);
}
