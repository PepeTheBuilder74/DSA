// RemoveNumbers-Codechef

/*
Two players are playing a game. They are given an array A1,A2,…,ANA_1, A_2, \ldots, A_NA1​,A2​,…,AN​ as well as an array B1,B2,…,BMB_1, B_2, \ldots,
B_MB1​,B2​,…,BM​. The game consists of MMM rounds. Players are participating in rounds alternatively. During the iii-th round (for iii from 111 to MMM)
the corresponding player (first player, if iii is odd, and second if iii is even) has to do exactly one of the following: remove all elements
from the array AAA that are divisible by BiB_iBi​,remove all elements from the array AAA that are not divisible by BiB_iBi​.
The first player wants to minimize the sum of the remaining elements in the array AAA after all MMM rounds, and the second wants to maximize it.
Find the sum of the remaining elements in the array AAA after all MMM rounds if both players are playing optimally.

https://www.codechef.com/problems/RMVNUMBERS
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
const int MxN = 2e5;
// ar<int, 2> v1[MxN];
int n, m;
vector<ll> v1(MxN), v2(MxN);

ll rec(int i, vector<ll> v1)
{
    if (i == m || v1.size() == 0)
    {
        return accumulate(v1.begin(), v1.end(), 0ll);
    }
    vector<ll> divisible, notdivisible;
    for (auto &x : v1)
    {
        if (x % v2[i] != 0)
            notdivisible.push_back(x);
        else
            divisible.push_back(x);
    }

    // SECOND GUY TURN
    if (i & 1)
    {
        return max(rec(i + 1, notdivisible), rec(i + 1, divisible));
    }
    // FIRST GUY TURN
    else
    {
        return min(rec(i + 1, notdivisible), rec(i + 1, divisible));
    }
}

int main()
{
    cin >> n >> m;
    v1.resize(n), v2.resize(m);
    rep(i, n) cin >> v1[i];
    rep(i, m) cin >> v2[i];
    /* Before describing the solution for each individual block let’s prove the following lemma: if both players can remove
    all the elements from the array aaa using only their own rounds, then the answer is 000. Indeed, in such a case both players4
    can make the sum of the remaining elements in the array aaa equal to 000 regardless of the actions of the second player. The first
    player wants to minimize the sum, therefore the answer is not bigger than zero. At the same time, the second player wants to maximize
    the sum, therefore the answer is not less than zero. Thus the only possible answer is 000.

    O(log⁡n)O(\log n)O(logn) own rounds are enough for each player to remove all the elements. Indeed, at each round one of the two possible
    operations removes at least half of all remaining elements, therefore log2m rounds are always enough to remove all the elements.
    It means that the only difference from the third subtask is that we can just output 0 when m >100m by the lemma above.
    */

    if (m >= 29)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << rec(0, v1) << endl;
}