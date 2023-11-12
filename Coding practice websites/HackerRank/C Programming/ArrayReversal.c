// 20 points : https://www.hackerrank.com/domains/c?filters%5Bstatus%5D%5B%5D=solved
// Thuan - 23.11.11

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1000] = {};
    int num, i;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int j = num - 1; j >= 0; j--)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}
