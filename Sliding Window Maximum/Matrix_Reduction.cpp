// C - Index × A(Continuous ver.)
// atcoder 267 beginer contest
// solve it using maths ---> best explanation on soumya batharjee

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
const int MxN = 2e5;
ar<int, 2> v[MxN];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n), pref(n + 1, 0);
    // ll prefix = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += (i + 1) * v[i];
        // prefix += v[i];
    }
    ll ans = sum;
    for (int i = m; i < n; i++)
    {

        sum += m * v[i];
        sum -= pref[i] - pref[i - m];
        ans = max(ans, sum);
    }

    cout << ans << endl;
}
