/* 30 points : https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true
Thuan 23.10.17 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int q;
    cin >> n >> q;

    int k;
    vector <vector <int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int k = 0; k < q; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << arr[i][j] << endl;
    }

    return 0;
}