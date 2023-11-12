// 10 points : https://www.hackerrank.com/challenges/1d-arrays-in-c/problem?isFullScreen=true
// Thuan - 23.11.11

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, a;
    int sum = 0;
    int i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d", &a);
        sum += a;
        i++;
    }
    printf("%d", sum);
    return 0;
}