#include <stdio.h>
#include <stdlib.h>

void main()
{
    float AvrofYear[5] = {0, 0, 0, 0, 0};
    float temp;
    float RainFall[5][13] = {
        // Year Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec
        {2010, 12.1, 51.2, 12.3, 23.4, 12.5, 32.6, 12.7, 32.8, 23.9, 15.0, 24.1, 45.2},
        {2011, 32.1, 32.2, 23.3, 11.4, 32.5, 54.6, 23.7, 32.8, 32.9, 43.0, 12.1, 43.2},
        {2012, 22.1, 23.2, 23.3, 33.4, 23.5, 34.6, 12.7, 21.8, 33.9, 12.0, 33.1, 14.2},
        {2013, 11.1, 13.2, 43.3, 12.4, 34.5, 34.6, 23.7, 43.8, 34.9, 34.0, 23.1, 14.2},
        {2014, 45.1, 12.2, 34.3, 12.4, 34.5, 54.6, 12.7, 34.8, 54.9, 45.0, 13.1, 34.2},
    };
    printf("YEAR        RAINFALL\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 13; j++)
        {
            AvrofYear[i] += RainFall[i][j];
        }
        printf("%.0f         %.1f \n", RainFall[i][0], AvrofYear[i] / 12);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (AvrofYear[i] > AvrofYear[j])
            {
                temp = RainFall[i][0];
                RainFall[i][0] = RainFall[j][0];
                RainFall[j][0] = temp;
            }
        }
    }
    printf("Order of small to high of RainFail: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%.0f ", RainFall[i][0]);
    }
}