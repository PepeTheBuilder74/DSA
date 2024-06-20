#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
#define int long long
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
/*
GCD (Greatest Common Divisor) of two integers x and y is the maximum integer z by which both x and y are divisible. For example, GCD(36,48)=12, GCD(5,10)=5, and GCD(7,11)=1

.

Kristina has an array a
consisting of exactly n positive integers. She wants to count the GCD of each neighbouring pair of numbers to get a new array b

, called GCD-sequence.

So, the elements of the GCD-sequence b
will be calculated using the formula bi=GCD(ai,ai+1) for 1≤i≤n−1

.

Determine whether it is possible to remove exactly one number from the array a
so that the GCD sequence b is non-decreasing (i.e., bi≤bi+1

is always true).

For example, let Khristina had an array a
= [20,6,12,3,48,36]. If she removes a4=3 from it and counts the GCD-sequence of b

, she gets:

    b1=GCD(20,6)=2

b2=GCD(6,12)=
6
b3=GCD(12,48)=12
b4=GCD(48,36)=12

The resulting GCD sequence b = [2,6,12,12] is non-decreasing because b1≤b2≤b3≤b4.
*/
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto solve = [&](int tc)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<int> b = {0};
        for (int i = 1; i <= n - 1; i++)
        {
            b.push_back(__gcd(a[i], a[i + 1]));
        }
        b.push_back(1e18);
        vector<int> pref(n + 2), suff(n + 2);
        for (int i = 1; i <= n - 1; i++)
        {
            pref[i] = pref[i - 1] + (b[i] >= b[i - 1]);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            suff[i] = suff[i + 1] + (b[i] <= b[i + 1]);
        }
        if (pref[n - 2] == n - 2)
        {
            cout << "YES" << endl;
            return;
        }
        if (suff[2] == n - 2)
        {
            cout << "YES" << endl;
            return;
        }
        // dbg(b);

        // dbg(b);
        // dbg(pref);
        // dbg(suff);
        for (int i = 2; i <= n - 1; i++)
        {
            int g = __gcd(a[i - 1], a[i + 1]);
            // cout << a[i - 1] << ' ' << a[i + 1] << ' ' << pref[i - 2] << ' ' << suff[i + 2] << endl;
            if (pref[i - 2] + suff[i + 1] + (g >= b[i - 2] and g <= b[i + 1]) >= n - 2)
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    };
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
}