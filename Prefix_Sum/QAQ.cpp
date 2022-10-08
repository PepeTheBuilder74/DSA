// A.QAQ

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
const int MxN = 2e5;
ar<int, 2> v1[MxN];
int dp[101][101];

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0, q = 0, a = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Q')
        {
            cnt += a;
            q++;
        }
        else if (s[i] == 'A')
        {
            a += q;
        }
    }
    cout << cnt << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
