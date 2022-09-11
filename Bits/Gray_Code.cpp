// Gray Code-https://cses.fi/problemset/task/2205
// also with recurssion

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        bitset<32> r;
        r = i ^ (i >> 1);
        string s = r.to_string();
        cout << s.substr(32 - n) << endl;
    }
    return 0;
}
