// 10 points : https://www.hackerrank.com/challenges/for-loop-in-c/problem?isFullScreen=true
// Thuan - 23.10.21

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    // Complete the code.
    char lowercase_English[10][100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (size_t i = a; i < b + 1; i++)
    {
        if (i % 2 == 0)
        {
            if (i > 9)
                printf("%s\n", "even");
            else
                printf("%s\n", lowercase_English[i]);
        }
        else
        {
            if (i > 9)
                printf("%s\n", "odd");
            else
                printf("%s\n", lowercase_English[i]);
        }
    }

    return 0;
}
