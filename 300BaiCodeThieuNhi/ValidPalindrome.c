#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s)
{
    char convertstring[100000];
    char deletemarks[100000];
    int sizeofdelete = 0;
    bool result;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 32)
            result = true;

        if (s[i] >= 65 && s[i] <= 90)
            s[i] = s[i] + 32;

        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            deletemarks[sizeofdelete] = s[i];
            sizeofdelete++;
        }
    }
    for (int i = 0; i < sizeofdelete; i++)
    {
        convertstring[i] = deletemarks[sizeofdelete - 1 - i];
        if (convertstring[i] == deletemarks[i])
        {
            result = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    return result;
}

void main()
{
    char string[] = "01ab Ba10";
    printf("result = %d", isPalindrome(string));
}