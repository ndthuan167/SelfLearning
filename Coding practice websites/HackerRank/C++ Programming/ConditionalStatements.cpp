/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem?isFullScreen=true
Thuan 23.10.17 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // Write your code here
    
    string lowercase_English[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string lowercase_English_more_9 = "Greater than 9";

    for (size_t i = 0; i <= 9; i++)
    {
        if (n == i)
        {
            cout << lowercase_English[i] << endl;
        }
    }
    if (n > 9)
    {
        cout << lowercase_English_more_9 << endl;
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
