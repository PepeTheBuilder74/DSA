// 1729D - Friends and the Restaurant

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
        int n;
        cin >> n;
        vector<int> c1(n), c2(n), d(n);
        rep(i, n) cin >> c1[i];
        rep(i, n) cin >> c2[i];
        rep(i, n) d[i] = c2[i] - c1[i];
        sort(d.begin(), d.end());
        int i = 0, j = n - 1, ans = 0;
        while (i < j)
        {
            if (d[i] + d[j] >= 0)
            {
                i++, j--, ans++;
            }
            else
            {
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}