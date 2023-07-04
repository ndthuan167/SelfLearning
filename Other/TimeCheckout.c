#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void CalculateTimeOut()
{
    int TimeIn, Hour , Minute;
    int HourOut,  MinuteOut;

    printf("Please enter your Time In follow format: hourminute. Ex: 810 ~ 8:10\n");
    printf("Enter the your time in: ");
    scanf("%d", &TimeIn);
    printf("---------------------------\n");
        Hour = TimeIn/100;
        Minute = TimeIn - Hour*100;
        if (Hour >= 10)
            printf("Your Time in is: %d", Hour);
        else
            printf("Your Time in is: 0%d", Hour);
            printf(":");
            printf("%d\n", Minute);
    printf("---------------------------");
        HourOut = Hour + 9 + (Minute + 48)/60 ;
        MinuteOut = (Minute + 48)%60 ;
            printf("\nYour Time Out is: %d ", HourOut);
            printf(":");
        if (MinuteOut >= 10)
            printf("%d ", MinuteOut);
        else
            printf("0%d ", MinuteOut);
    printf("\n");
    system("pause");

}
int main()
{
    CalculateTimeOut();
    return 0 ;
}
