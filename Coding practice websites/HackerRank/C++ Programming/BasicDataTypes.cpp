/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true
Thuan 23.10.17 */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int a;
    long b;
    char c;
    float d;
    double e;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%f\n%lf", a, b, c, d, e);

    return 0;
}