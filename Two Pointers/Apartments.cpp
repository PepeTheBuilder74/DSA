// https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll m, n, k;
    cin >> m >> n >> k;
    vector<ll> v1(m), v2(n);
    rep(i, m) cin >> v1[i];
    rep(i, n) cin >> v2[i];
    ll ans = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && v2[j] + k < v1[i])
        {
            j++;
        }
        if (j < n && v2[j] <= v1[i] + k)
        {
            ans++;
            j++;
        }
    }

    cout << ans << endl;
    return 0;
}
