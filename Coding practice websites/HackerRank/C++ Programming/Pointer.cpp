/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true
Thuan 23.10.17 */

#include <stdio.h>
#include <math.h>

void update(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *a + *b;
    *b = abs(temp - *b);
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}