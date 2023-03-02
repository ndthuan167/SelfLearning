#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int random_number;
    int guess_number = 0;
    int timeofguess = 5;
    srand((unsigned)time(&t));
    random_number = rand() % timeofguess;
    while (timeofguess > 0)
    {
        printf("Please enter your guess number: ");
        scanf("%d", &guess_number);
        if (guess_number < 0 || guess_number > timeofguess)
        {
            printf("Your guess number is higher limit!!\n");
        }
        else
        {
            if (guess_number != random_number)
            {
                if (guess_number < random_number)
                {
                    printf("Your guess number is lower the random number!!\n");
                }
                else
                {
                    printf("Your guess number is higher the random number!!\n");
                }
            }
            else
            {
                printf("Congratulation!!! Your guess number is TRUE!!!\n");
                printf("The random number is : %d", random_number);
                break;
            }
        }
        timeofguess--;
    }
    printf("Can't guess continue!!");
    return (0);
}