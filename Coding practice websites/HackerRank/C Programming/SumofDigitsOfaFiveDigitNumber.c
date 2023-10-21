// 15 points : https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem?isFullScreen=true
// Thuan - 23.10.21

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

    int sum = 0;
    int divide_number = 10;

    int index = 5;

    while (index > 0)
    {
        sum += n % divide_number;
        n /= divide_number;
        index--;
    }
    printf("%d", sum);
    return 0;
}