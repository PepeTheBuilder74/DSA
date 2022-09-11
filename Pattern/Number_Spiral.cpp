

// https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll z = max(x, y);
        ll z1 = z;
        if (z & 1)
        {
            z = z * z;
            ll ans = abs(x - 1) + abs(y - z1);
            cout << z - ans << endl;
        }
        else
        {
            z--;
            z *= z;
            z += 1;
            ll ans = abs(x - 1) + abs(y - z1);

            cout << z + ans << endl;
        }
    }
}
