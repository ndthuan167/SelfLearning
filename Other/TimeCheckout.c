#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Time
{
    int Hour;
    int Minute;
} TimeIN, TimeOUT, TimeWork;

TimeIN ShowTimeOfYourTimeIn(char *TimeIn);

void CheckTimeInDay(int Hour, int Minute);
void CheckTimeInFriday(int Hour, int Minute);

enum YourSlection
{
    CHECK_IN_DAY = 1,
    CHECK_IN_FRIDAY,
};

int main()
{
    int selection;
    char TimeIn[5];
    printf("Enter your time in: ");
    scanf("%s", TimeIn);
    printf("\n");

    printf("* 1. Check time out on today.     *\n");
    printf("* 2. Check time out on Friday.  *\n");
    printf("\n");

    printf("Enter your selection: ");
    scanf("%d", &selection);

    while (selection != CHECK_IN_DAY && selection != CHECK_IN_FRIDAY)
    {
        printf("Please re-enter your selection: ");
        scanf("%d", &selection);
    }

    switch (selection)
    {
    case CHECK_IN_DAY:
        CheckTimeInDay(ShowTimeOfYourTimeIn(TimeIn).Hour, ShowTimeOfYourTimeIn(TimeIn).Minute);
        break;
    case CHECK_IN_FRIDAY:
        CheckTimeInFriday(ShowTimeOfYourTimeIn(TimeIn).Hour, ShowTimeOfYourTimeIn(TimeIn).Minute);
        break;
    default:
        // Nothing to do
        break;
    }

    return 0;
}

TimeIN ShowTimeOfYourTimeIn(char *TimeIn)
{
    int size = sizeof(TimeIn) / sizeof(TimeIn[0]);
    int indexof58;
    int Hour, Minute;

    TimeIN timein;

    for (int i = 0; i < size; i++)
    {
        if (TimeIn[i] == 58)
        {
            indexof58 = i;
        }
    }
    if (indexof58 == 1)
    {
        Hour = (int)TimeIn[0] - 48;
    }
    else
    {
        Hour = 10 + (int)(TimeIn[1] - 48);
    }
    Minute = (int)(TimeIn[indexof58 + 1] - 48) * 10 + (int)(TimeIn[indexof58 + 2] - 48);

    timein.Hour = Hour;
    timein.Minute = Minute;

    return timein;
}
void CheckTimeInDay(int Hour, int Minute)
{
    TimeOUT timeout10, timeout88;

    timeout10.Hour = Hour + 11;
    timeout10.Minute = Minute;

    timeout88.Hour = Hour + 9 + (Minute + 48) / 60;
    timeout88.Minute = (Minute + 48) % 60;

    printf("Your time out if you work 10 hours is: %d", timeout10.Hour);
    printf(":");
    if (timeout10.Minute >= 10)
        printf("%d ", timeout10.Minute);
    else
        printf("0%d ", timeout10.Minute);
    printf("\n");
    printf("Your time out if you work 8.8 hours is: %d", timeout88.Hour);
    printf(":");
    if (timeout88.Minute >= 10)
        printf("%d ", timeout88.Minute);
    else
        printf("0%d ", timeout88.Minute);

    printf("\n");
    system("pause");
}

void CheckTimeInFriday(int Hour, int Minute)
{
    char yourtimeworkFriday[5];
    printf("Enter your time have to work on Friday: ");
    scanf("%s", yourtimeworkFriday);

    TimeWork timeworkFriday;
    TimeOUT timeOutonFriday;

    timeworkFriday.Hour = ShowTimeOfYourTimeIn(yourtimeworkFriday).Hour;
    timeworkFriday.Minute = ShowTimeOfYourTimeIn(yourtimeworkFriday).Minute;

    timeOutonFriday.Minute = Minute + timeworkFriday.Minute;
    if (timeOutonFriday.Minute >= 60)
    {
        timeOutonFriday.Hour = (Hour + 1) + timeworkFriday.Hour + 1;
        timeOutonFriday.Minute = timeOutonFriday.Minute - 60;
    }
    else
    {
        timeOutonFriday.Hour = (Hour + 1) + timeworkFriday.Hour;
        timeOutonFriday.Minute = Minute + timeworkFriday.Minute;
    }
    printf("Your time out on Friday is: %d", timeOutonFriday.Hour);
    printf(":");
    if (timeOutonFriday.Minute >= 10)
        printf("%d ", timeOutonFriday.Minute);
    else
        printf("0%d ", timeOutonFriday.Minute);

    printf("\n");
    system("pause");
}