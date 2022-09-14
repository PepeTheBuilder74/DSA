// https: // cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, m;
    cin >> n >> m;

    // pair because we dont want to erase all the tickets of same price
    set<pair<ll, int>> s;
    rep(i, n)
    {
        ll x;
        cin >> x;
        s.insert({x, i});
    }
    ll ans = 0;
    rep(i, m)
    {
        ll x;
        cin >> x;
        auto it = s.lower_bound({x, 0});
        if (it == s.end() || (*it).first > x)
        {
            // if element is not there
            if (it == s.begin())
            {
                cout << -1 << endl;
            }
            else
            {
                --it;
                cout << (*it).first << endl;
                s.erase(it);
            }
        }
        else
        {

            cout << (*it).first << endl;
            s.erase(it);
        }
    }
    return 0;
}
