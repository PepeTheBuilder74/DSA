#include <bits/stdc++.h>
using namespace std;
#define fr(i, n) for (int i = 0; i < n; i++)
#define fra(i, a, b) for (int i = a; i < b; i++)
#ifdef LOCAL
#include "coding.h"
#else
#define dbg(x...)
#endif
#define ff first
#define ss second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double lld;
typedef unsigned long long int ull;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define popll __builtin_popcountll
#define popc __builtin_popcount
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
#define each(x, a) for (auto &x : a)
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vpii = vector<pii>;
using vpll = vector<pll>;

template <typename T>
void ckmin(T &a, const T &b)
{
    a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T1, class T2>
void re(pair<T1, T2> &p);
template <class T>
void re(vector<T> &a);
template <class T, size_t SZ>
void re(array<T, SZ> &a);

template <class T>
void re(T &x) { cin >> x; }
void re(double &x)
{
    string t;
    re(t);
    x = stod(t);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest)
{
    re(first);
    re(rest...);
}

template <class T1, class T2>
void re(pair<T1, T2> &p) { re(p.ff, p.ss); }
template <class T>
void re(vector<T> &a)
{
    for (int i = 0; i < sz(a); i++)
        re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ> &a)
{
    for (int i = 0; i < SZ; i++)
        re(a[i]);
}
// write

template <class T>
void write(T x)
{
    cout << x << " ";
}

template <class T>
void writen(T x)
{
    cout << x << endl;
}
const int MxN = 2000100;
const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;
const int N = 2e5 + 5;
const ll INF = 1e18;

void solve()
{
    int n, m, k;
    re(n, m, k);
    vpll adj[n + 1];
    fr(i, m)
    {
        ll a, b, c;
        re(a, b, c);
        adj[a].pb({b, c});
    }
    // every vertex can have atmost k shortest, so we will store all shortest path ending at vertex x
    priority_queue<ll> pq[n + 1];
    pq[1].push(0);
    priority_queue<pll, vpll, greater<pll>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (pq[u].size() == k && pq[u].top() < d)
            continue;

        for (auto [v, w] : adj[u])
        {
            if (pq[v].size() < k)
            {
                pq[v].push(d + w);
                q.push({d + w, v});
            }
            else if (pq[v].top() > d + w)
            {
                pq[v].pop();
                pq[v].push(d + w);
                q.push({d + w, v});
            }
        }
        // all nodez will have exactly k shortest path ending at them so we will do relaxation for all nodes for  k times

        // priority_queue debug = pq[u];
        // cout << u << " ";
        // while (!debug.empty())
        // {
        //     cout << debug.top() << " ";
        //     debug.pop();
        // }
        cout << endl;
    }

    vector<ll> ans;
    while (!pq[n].empty())
    {
        ans.pb(pq[n].top());
        pq[n].pop();
    }
    reverse(all(ans));
    fr(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    dbg(ans);
}

int main()
{
    // remove for interactive problemsa
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        solve();
    }
    return 0;
}