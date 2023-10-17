/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem?isFullScreen=true
Thuan 23.10.17 */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // Complete the code.
    int a;
    int b;
    cin >> a;
    cin >> b;

    string lowercase_English[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (size_t i = a; i < b + 1; i++)
    {
        if (i % 2 == 0)
        {
            if (i > 9)
                cout << "even" << endl;
            else
                cout << lowercase_English[i] << endl;
        }
        else
        {
            if (i > 9)
                cout << "odd" << endl;
            else
                cout << lowercase_English[i] << endl;
        }
    }

    return 0;
}