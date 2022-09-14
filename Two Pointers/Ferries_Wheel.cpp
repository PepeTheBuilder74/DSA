// https: // cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
vector<ll> v(200001);

int main()
{
    int n;
    ll x;
    cin >> n >> x;

    rep(i, n) cin >> v[i];
    sort(v.begin(), v.begin() + n);
    ll ans = 0;
    for (int i = 0, j = n - 1; i <= j;)
    {
        while (i <= j && v[i] + v[j] > x)
        {
            j--;
            ans++;
        }

        if (i <= j)
        {
            i++;
            j--;
            ans++;
        }
    }

    cout << ans << endl;
}
