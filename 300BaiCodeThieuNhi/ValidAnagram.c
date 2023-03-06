#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    int count = 0;
    if (strlen(s) != strlen(t))
        return false;
    else
    {
        for (int i = 0; i < strlen(t); i++)
        {
            for (int j = 0; j < strlen(s); j++)
            {
                if (t[i] == s[j])
                {
                    s[j] = 32;
                    count++;
                    break;
                }
            }
        }
        if (count == strlen(s))
            return true;
        else
            return false;
    }
}

void main()
{
    char string1[] = "ccac";
    char string2[] = "aacc";
    printf("%d", isAnagram(string1, string2));
}