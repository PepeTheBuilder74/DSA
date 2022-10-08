// C. Digital Logarithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double lld;
typedef unsigned long long int ull;
const int MxN = 2e5;
// ar<int, 2> v1[MxN];
// vector<int> v(MxN);
void solve()
{
    int n1;
    cin >> n1;
    multiset<int, greater<int>> s1, s2;
    rep(i, n1)
    {
        int x;
        cin >> x;
        s1.insert(x);
    }
    rep(i, n1)
    {
        int x;
        cin >> x;
        s2.insert(x);
    }
    int cnt = 0;
    while (s1.size())
    {
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        if (*it1 == *it2)
        {
            s1.erase(it1);
            s2.erase(it2);
        }
        else if (*it1 > *it2)
        {
            s1.insert(to_string(*it1).size());
            s1.erase(it1);
            cnt++;
        }
        else
        {
            s2.insert(to_string(*it2).size());
            s2.erase(it2);
            cnt++;
        }
    }

    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
