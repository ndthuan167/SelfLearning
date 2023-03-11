#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
    First function check the ransomNote is a Subarray of magazine.
    This function can check that all elements in ransomNote appear in magazine.
*/
bool canConstructSubarray(char *ransomNote, char *magazine)
{
    int number[0xFF];
    int index = 0;
    bool check;
    bool result = false;
    for (int i = 0; i < strlen(magazine); i++)
    {
        if (magazine[i] == ransomNote[0])
        {
            number[index] = i;
            index++;
        }
    }
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < strlen(ransomNote); j++)
        {
            if (ransomNote[j] == magazine[number[i] + j])
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            result = true;
        }
    }
    return result;
}
/*
    This function can check that all elements in ransomNote appear in magazine.
    This function can't check ransomNote is a Subarray of magazine
*/
bool canConstruct(char *ransomNote, char *magazine)
{
    int count = 0;
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        for (int j = 0; j < strlen(magazine); j++)
        {
            if (ransomNote[i] == magazine[j])
            {
                magazine[j] = 32;
                count++;
                break;
            }
        }
    }
    if (count == strlen(ransomNote))
        return true;
    else
        return false;
}

void main()
{
    char ransomNote[] = "aab";
    char magazine[] = "baa";
    int selection;
    printf("Do you want check the ransomNote is a Subarray of magazine? : ");
    scanf("%d", &selection);
    if (selection == 1)
        printf("%d", canConstructSubarray(ransomNote, magazine));   //FALSE
    else
        printf("%d", canConstruct(ransomNote, magazine));       //TRUE
}