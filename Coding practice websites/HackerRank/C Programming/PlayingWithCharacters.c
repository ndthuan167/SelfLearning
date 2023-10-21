// 5 points : https://www.hackerrank.com/challenges/playing-with-characters/problem?isFullScreen=true
// Thuan - 23.10.21

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch ;
    char s[128];
    char sen[128];

    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}