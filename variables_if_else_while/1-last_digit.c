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
    printf("Last digit of %d is %d and is ", n, n % 10);

    if (n % 10 > 5)
    {
        printf("greater than 5\n");
    }
    else if (n % 10 < 6 && n % 10 != 0)
    {
        printf("less than 6 and not 0\n");
    }
    else
    {
        printf("0\n");
    }
    
	return (0);
}
