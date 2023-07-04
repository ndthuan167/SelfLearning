#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  In this code. I just discribe the operation of the stack space.
    I just can simulate with one type of data ex: int/char,...
*/

int *Push(int number, int *Stack)
{
    int numberpush;
    printf("Plese enter the number that you want push: ");
    scanf("%d", &numberpush);

    Stack[number - 1] = numberpush;
    return Stack;
}

void PrintStack(int number, int *Stack)
{
    printf("The Stack is : \n");
    for (int i = number - 1; i >= 0; i--)
    {
        printf("%p\n", &Stack[i]);
    }
}

int *ContinuePush(int number, int *Stack)
{
    int numberpush;
    printf("Plese enter the number that you want push: ");
    scanf("%d", &numberpush);

    int Array[1000];

    for (int i = 0; i < number; i++)
    {
        Array[i] = Stack[i];
    }

    for (int i = 1; i < number; i++)
    {
        Stack[(number - 1) - i] = Array[(number - 1) - (i - 1)];
    }
    Stack[number - 1] = numberpush;
    return Stack;
}

int main()
{
    int Stack[10000];
    int operation;
    int numberofpush = 0;
    int MaxSizeofStack = 4; // Space of Stack be share by RAM (bits)
    int *StackPoiter;
    int *AddressPop;
    int SelectionStOverflow;
    // 1: Push  2: Pop
    while (1)
    {
        printf("Please enter the operation that you want (Push/Pop): ");
        scanf("%d", &operation);

        if (operation == 0)
            break;

        if (numberofpush == 0 && operation == 2)
        {
            printf("Can't Pop!!. The Stack is empty! \n");
            break;
        }

        if (operation == 1)
        {
            numberofpush++;
            if (numberofpush > MaxSizeofStack)
            {
                printf("Please enter selection when Stack overflow: "); // 1: Continue Push   0: Don't Push
                scanf("%d", &SelectionStOverflow);
                numberofpush = MaxSizeofStack;
                if (SelectionStOverflow == 1)
                {
                    ContinuePush(MaxSizeofStack, Stack);
                }
                else
                {
                    printf("Stack Overflow !!!\n");
                    PrintStack(numberofpush, Stack);
                    break;
                }
            }
            else
            {
                Push(numberofpush, Stack);
            }
        }
        else if (operation == 2)
        {
            numberofpush--;
            AddressPop = &Stack[numberofpush];
            printf("Address of value Pop is: %p\n", AddressPop);

            if (numberofpush == 0)
            {
                printf("The Stack is empty!!");
                break;
            }
        }
        else
            printf("Incorrect Operation!. Please re-enter !!\n");

        StackPoiter = &Stack[numberofpush - 1];

        PrintStack(numberofpush, Stack);

        printf("StackPoiter is: %p\n", StackPoiter);
    }

    return 0;
}
