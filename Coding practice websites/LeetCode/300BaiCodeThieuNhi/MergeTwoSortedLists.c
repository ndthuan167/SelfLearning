#include <stdio.h>
#include <stdlib.h>

int *mergeTwoLists(int *list1, int *list2, int sizeoslist1, int sizeoflist2)
{
    int mergelist[sizeoslist1 + sizeoflist2];
    int *resultmergelist = mergelist;
    for (int i = 0; i < sizeoslist1; i++)
    {
        mergelist[i] = *(list1 + i);
    }
    for (int i = sizeoslist1; i < sizeoslist1 + sizeoflist2; i++)
    {
        mergelist[i] = *(list2 + (i - sizeoslist1));
    }
    for (int i = 0; i < sizeoslist1 + sizeoflist2 - 1; i++)
    {
        for (int j = i + 1; j < sizeoslist1 + sizeoflist2; j++)
        {
            if (mergelist[i] > mergelist[j])
            {
                int temp;
                temp = mergelist[j];
                mergelist[j] = mergelist[i];
                mergelist[i] = temp;
            }
        }
    }
    return resultmergelist;
}

int main(void)
{
    int list1[] = {1, 2, 4, 2, 3};
    int list2[] = {1, 2, 0, 5, 1, 2};
    int sizeoflist1 = sizeof(list1) / sizeof(list1[0]);
    int sizeoflist2 = sizeof(list2) / sizeof(list2[0]);
    for (int i = 0; i < sizeoflist1 + sizeoflist2; i++)
    {
        printf("%d ", *(mergeTwoLists(list1, list2, sizeoflist1, sizeoflist2) + i));
    }

    return 0;
}