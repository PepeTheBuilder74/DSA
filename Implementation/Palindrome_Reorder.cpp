#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    int cnt = 0;
    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            cnt++;
        }
        if (cnt > 1)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    string ans = "";
    for (auto x : mp)
    {
        if (x.second % 2 == 0)
        {
            for (int i = 0; i < x.second / 2; i++)
            {
                ans.push_back(x.first);
            }
        }
    }
    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());
    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            for (int i = 0; i < x.second; i++)
            {
                ans.push_back(x.first);
            }
        }
    }
    ans += ans2;
    cout << ans;
    return 0;
}
