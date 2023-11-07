/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true
Thuan 23.11.07 */

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> number_seperate{};
    string temp = "";
    char del = ',';

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] != del)
        {
            temp += str[i];
        }
        else
        {
            number_seperate.push_back(stoi(temp));
            temp = "";
        }
    }
    number_seperate.push_back(stoi(temp));

    return number_seperate;
}
int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}