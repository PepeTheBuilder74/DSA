// C - Submask
https://atcoder.jp/contests/abc269/tasks/abc269_c
// sum over subset

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
    ll n;
    cin >> n;
    vector<ll> v;

    // only explore the subsets of n
    for (ll s = n; s > 0; s = (s - 1) & n)
    {
        v.push_back(s);
    }
    v.push_back(0);
    reverse(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << endl;
    }
}

// https://codeforces.com/blog/entry/45223 --> this is the best explanation of this code
