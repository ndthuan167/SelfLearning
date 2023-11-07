/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true
Thuan 23.11.07 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Complete the program
    string a;
    string b;
    cin >> a >> b;
    int size_a, size_b;
    string c;

    size_a = a.size();
    size_b = b.size();
    c = a + b;
    
    string a_switched, b_switched;
    a_switched = b[0];
    for (size_t i = 1; i < size_a; i++)
        a_switched += a[i];
    b_switched = a[0];
    for (size_t i = 1; i < size_b; i++)
        b_switched += b[i];

    cout << size_a << " " << size_b << endl;
    cout << c << endl;
    cout << a_switched << " " << b_switched << endl;
    return 0;
}