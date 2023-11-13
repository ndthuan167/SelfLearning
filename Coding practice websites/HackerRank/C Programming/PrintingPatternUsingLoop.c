// 30 points : https://www.hackerrank.com/challenges/printing-pattern-2/problem?isFullScreen=true
// Thuan - 23.11.13

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.

    int result[2 * n - 1][2 * n - 1];

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < 2 * n - 1 - i; j++)
        {
            result[i][j] = n - i;
            result[2 * (n - 1) - i][j] = n - i;
            result[j][i] = n - i;
            result[j][2 * (n - 1) - i] = n - i;
        }
    }

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            printf("%d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
