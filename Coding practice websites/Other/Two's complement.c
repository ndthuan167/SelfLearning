#include <stdio.h>
#include <stdlib.h>

int *DectoBin(int number);
int *ConvertToTwoCompement(int *binaryOne);

int main()
{
    int number;
    int *result;
    printf("Please enter your number to convert to negative in binary: ");
    scanf("%d", &number);
    result = ConvertToTwoCompement(DectoBin(number));
    printf("The binary of %d is : ", -number);
    for (int i = 0; i < 8; i++)
    {
        printf("%d", *(result + i));
        if (i == 3)
            printf(" ");
    }
    printf("\n");
    system ("pause");
    return 0;
}

int *DectoBin(int number)
{
    static int ArrayBin[8] ;

    for (int i = 7; (i >= 0) || (number / 2 != 0); i--)
    {
        if (number % 2 == 0)
        {
            ArrayBin[i] = 0;
        }
        else
            ArrayBin[i] = 1;

        number = number / 2;
    }
    printf("BinaryCode : ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", *(ArrayBin + i));
        if (i == 3)
            printf(" ");
    }
    printf("\n");

    return ArrayBin;
}

int *ConvertToTwoCompement(int *binaryOne)
{
    int *ArrayAfterConvert = binaryOne;
    int index;

    for (int i = 7; i >= 0; i--)
    {
        if (*(ArrayAfterConvert + i) == 1)
        {
            index = i;
            break;
        }
    }
    for (int i = index - 1; i >= 0; i--)
    {
        if (*(ArrayAfterConvert + i) == 0)
            *(ArrayAfterConvert + i) = 1;
        else
            *(ArrayAfterConvert + i) = 0;
    }
    return ArrayAfterConvert;
}
