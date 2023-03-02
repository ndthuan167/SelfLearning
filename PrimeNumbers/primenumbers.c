#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primenumber[1000];
    int numberofprime = 0;
    int min = 2;
    int max = 1000;
    for (int k = min; k <= max; k++)
    {
        for (int i = 2; i < k; i++)
        {
            if (k % i != 0)
            {
                if (i == k - 1)
                {
                    numberofprime++;
                    primenumber[numberofprime - 1] = k;
                }
            }
            else
            {
                break;
            }
        }
    }
    printf("Array of prime number from %d -> %d is : ", min, max);
    for (int i = 0; i < numberofprime; i++)
    {
        printf("%d ", primenumber[i]);
    }
    return 0;
}