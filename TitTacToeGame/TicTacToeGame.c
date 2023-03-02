#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tictactoearray[3][3];
char printtictac[][9] = {"---", "---", "---"};
int youwin = 0;
int competitorwin = 0;

void Fight()
{
    for (int i = 0; i < 3; i++)
    {
// Hang
        if((tictactoearray[i][0] == tictactoearray[i][1]) 
        && (tictactoearray[i][1] == tictactoearray[i][2]))
        {
            if(tictactoearray[i][2] == 5)
            {
                printf("You win !\n");
                youwin = 1;
                break;
            }
            else if (tictactoearray[i][2] == 3)
            {
                printf("Competitor win !\n");
                competitorwin = 1;
                break;
            }
        }
// Cot
        if((tictactoearray[0][i] == tictactoearray[1][i]) 
        && (tictactoearray[1][i] == tictactoearray[2][i]))
        {
            if(tictactoearray[2][i] == 5)
            {
                printf("You win !\n");
                youwin = 1;
                break;
            }
            else if (tictactoearray[2][i] == 3)
            {
                printf("Competitor win !\n");
                competitorwin = 1;
                break;
            }
        }
    }
// Cheo
        if (((tictactoearray[0][0] == tictactoearray[1][1]) 
        && (tictactoearray[1][1] == tictactoearray[2][2]) 
        && (tictactoearray[0][0] != 0))
        || ((tictactoearray[0][2] == tictactoearray[1][1]) 
        && (tictactoearray[1][1] == tictactoearray[2][0])
        && (tictactoearray[0][2] != 0)))
        {
            if(tictactoearray[1][1] == 5)
            {
                youwin = 1;
                printf("You win!! \n");
            }
            else if (tictactoearray[1][1] == 3)
            {
                competitorwin = 1;
                printf("Competitor win!! \n");
            }
        }
}
void PrintTicTacToeArray()
{
    int number = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(tictactoearray[i][j] == 5)
            {
                printtictac[i][j] = 'O';
            }
            else if (tictactoearray[i][j] == 3)
            {
                printtictac[i][j] = 'X' ;
            }
            printf("| %c ", printtictac[i][j]);
            if (j == 2)
            {
                printf("|\n");
            }
            if ((i == 0 && j == 2) || (i == 1 && j == 2))
            {
                printf("-------------\n");
            }
        }
    }   
}
void YourSelection()
{
    int y_hang, y_cot;
    int x_hang, x_cot;
    int num = 9;
        printf("Syntax for selection: <row>,<columb> (Ex: 1,2) \n");
        printf("You: O | Competitor: X \n");
    while (num > 0)
    {
        if (num % 2 != 0)
        {
            printf("Please enter your selection: ");
            scanf("%d,%d", &y_hang, &y_cot);
            if (tictactoearray[y_hang][y_cot] == 0)
            {
                tictactoearray[y_hang][y_cot] = 5;
                num--;
                Fight();
            }
            else
            {
                printf("Please re-enter your selection: \n");
            }
        }
        else
        {
            printf("Please enter competitor selection: ");
            scanf("%d,%d", &x_hang, &x_cot);
            if (tictactoearray[x_hang][x_cot] == 0)
            {
                tictactoearray[x_hang][x_cot] = 3;
                num--;
                Fight();
            }
            else
            {
                printf("Please re-enter competitor selection: \n");
            }
        }
        PrintTicTacToeArray();
        if( youwin == 1 || competitorwin == 1)
            break;
    }
    printf("Finish!!");
}
int main()
{
    PrintTicTacToeArray();
    YourSelection();
    return 0;
}