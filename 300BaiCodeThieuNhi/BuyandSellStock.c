#include <stdio.h>
int maxProfit(int *prices, int pricesSize)
{
    int MaxProfit = 0;
    for (int i = 0; i < pricesSize - 1; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            if (*(prices + j) - *(prices + i) > MaxProfit)
                MaxProfit = *(prices + j) - *(prices + i);
        }
    }
    return MaxProfit;
}
void main()
{
    int prices[] = {7,1,5,3,6,4,12,34,2,1};
    int sizeofprices = sizeof(prices) / sizeof(prices[0]);

    printf("%d", maxProfit(prices, sizeofprices));
}