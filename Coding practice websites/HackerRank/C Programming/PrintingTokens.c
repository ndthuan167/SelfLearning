// 20 points : https://www.hackerrank.com/challenges/printing-tokens-/problem?isFullScreen=true
// Thuan - 23.11.11

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char a[1000] = "";
    scanf("%[^\n]", a);

    for (int i = 0; i < strlen(a); i++)
    {
        printf("%c", a[i]);
        if (a[i] == ' ')
            printf("\n");
    }

    return 0;
}
