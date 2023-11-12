// 25 points : https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true
// Thuan - 23.11.11

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char string[1000] = "";
    scanf("%s", string);
    int count = 0;
    int i = 0;

    while (i < 10)
    {
        for (size_t j = 0; j < strlen(string); j++)
        {
            if ((int)string[j] == i + 48)
                count++;
        }
        printf("%d ", count);
        count = 0;
        i++;
    }

    return 0;
}
