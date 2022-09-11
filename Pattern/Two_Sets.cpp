// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> v1, v2;
    int j = 0;
    if (n % 4 == 3)
    {
        j = 3;
    }
    if (n % 4 == 0)
    {
        j = 4;
    }
    if (j == 3)
    {
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    if (j == 4)
    {
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(2);
        v2.push_back(3);
    }
    for (int i = 0; i < (n - 1) / 4; i++)
    {
        v1.push_back(4 * i + 1 + j);
        v1.push_back(4 * i + 4 + j);
        v2.push_back(4 * i + 2 + j);
        v2.push_back(4 * i + 3 + j);
    }

    cout << "YES" << endl;
    cout << v1.size() << endl;
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << v2.size() << endl;
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
}