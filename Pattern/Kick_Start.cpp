
// KICK_START
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int T;
    cin >> T;
    int i = 1;
    while (T--)
    {
        cout << "Case #" << i << ": ";
        i++;

        string s;
        cin >> s;
        string a = "KICK", b = "START";
        int n = s.length();
        int a1 = 0, b1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 >= a.size() && s.substr(i + 1 - a.size(), a.size()) == a)
            {
                a1++;
            }
            if (i >= b.size() && s.substr(i + 1 - b.size(), b.size()) == b)
            {
                b1 += a1;
            }
        }
        cout << b1 << endl;
    }
}
