#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*Three conditions for a string to be true for parentheses:
    1. The length of the string is an even number
    2. The number of opening brackets is equal to the number of closing brackets
    3. The first element of each array type is the opening brace and the last element of the array is the closing brace.
*/
bool isValid(char *s)
{
    int size = strlen(s);
    int numbers[6] = {1, 1, 1, 1, 1, 1};
    char curlybrackets[100];
    char roundbrackets[100];
    char squarebrackets[100];
    bool conditioncurly, conditionround, conditionsquare;
    if (size % 2 != 0)
        return false;
    for (int i = 0; i < size; i++)
    {
        switch (*(s + i))
        {
        case '{':
            curlybrackets[numbers[0] + numbers[1]] = *(s + i);
            numbers[0]++;
            break;
        case '}':
            curlybrackets[numbers[0] + numbers[1]] = *(s + i);
            numbers[1]++;
            break;
        case '(':
            roundbrackets[numbers[2] + numbers[3]] = *(s + i);
            numbers[2]++;
            break;
        case ')':
            roundbrackets[numbers[2] + numbers[3]] = *(s + i);
            numbers[3]++;
            break;
        case '[':
            squarebrackets[numbers[4] + numbers[5]] = *(s + i);
            numbers[4]++;
            break;
        case ']':
            squarebrackets[numbers[4] + numbers[5]] = *(s + i);
            numbers[5]++;
            break;
        default:
            break;
        }
    }

    if (((numbers[0] + numbers[1]) % 2 == 0) && ((numbers[2] + numbers[3]) % 2 == 0) && ((numbers[4] + numbers[5]) % 2 == 0) && (numbers[0] == numbers[1]) && numbers[2] == numbers[3] && numbers[4] == numbers[5])
    {
        if ((curlybrackets[2] == '{' && curlybrackets[(numbers[0] + numbers[1]) - 1 ] == '}') || ((numbers[0] + numbers[1]) == 2))
            conditioncurly = true;
        else
            conditioncurly = false;
        if ((roundbrackets[2] == '(' && roundbrackets[(numbers[2] + numbers[3]) - 1] == ')') || ((numbers[2] + numbers[3]) == 2))
            conditionround = true;
        else
            conditionround = false;
        if ((squarebrackets[2] == '[' && squarebrackets[(numbers[4] + numbers[5]) - 1] == ']') || (numbers[4] + numbers[5]) == 2)
            conditionsquare = true;
        else
            conditionsquare = false;
    }
    else
    {
        return false;
    }
    if (conditioncurly == true && conditionround == true && conditionsquare == true)
        return true;
    else
        return false;
}
void main()
{
    char string[] = "{}()[]";
    // 1: TRUE      0: FALSE
    printf("%d", isValid(string));
}