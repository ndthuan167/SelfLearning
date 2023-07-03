#include <stdio.h>

void main()
{
    int N;                  // number of testcase
    int numberofwire[1000]; // number of wire
    int higherofnode[1000][2];
    int numberofdot = 0;
    int result[100] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numberofwire[i]);

        for (int j = 0; j < numberofwire[i]; j++)
        {
            scanf("%d %d", &higherofnode[j][0], &higherofnode[j][1]);
            for (int k = 0; k < numberofwire[i]; k++)
            {
                if ((higherofnode[j][0] < higherofnode[k][0]) && (higherofnode[j][1] > higherofnode[k][1]) ||
                    (higherofnode[j][0] > higherofnode[k][0]) && (higherofnode[j][1] < higherofnode[k][1]))
                {
                    result[i]++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", result[i]);
    }
}