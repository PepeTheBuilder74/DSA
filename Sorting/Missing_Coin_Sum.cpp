// Missing Coin Sum
// You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    ll ans = 1;
    sort(v.begin(), v.end());
    rep(i, n)
    {
        if (ans < v[i])
        {
            break;
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}