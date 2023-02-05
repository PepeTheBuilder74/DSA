#include <bits/stdc++.h>
using namespace std;
#define fr(i, n) for (int i = 0; i < n; i++)
#define fra(i, a, b) for (int i = a; i < b; i++)
#ifndef ONLINE_JUDGE
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
//-----------------------CODE BEGINS-----------------------//
int n, m;
vll dist1(mxn, INF), dist2(mxn, INF);
vpll adj1[mxn];
vpll adj2[mxn];

void dijkstra1(int src)
{
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, src});
    dist1[src] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().ss;
        ll d = pq.top().ff;
        pq.pop();

        // to avoid TLE add this or else it will again visit all the neighbours of u
        if (d > dist1[u])
            continue;
        for (auto v : adj1[u])
        {
            if (dist1[v.ff] > dist1[u] + v.ss)
            {
                dist1[v.ff] = dist1[u] + v.ss;
                pq.push({dist1[v.ff], v.ff});
            }
        }
    }
}
void dijkstra2(int src)
{
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, src});
    dist2[src] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().ss;
        ll d = pq.top().ff;
        pq.pop();
        if (d > dist2[u])
            continue;
        for (auto v : adj2[u])
        {
            if (dist2[v.ff] > dist2[u] + v.ss)
            {
                dist2[v.ff] = dist2[u] + v.ss;
                pq.push({dist2[v.ff], v.ff});
            }
        }
    }
}

void solve()
{
    re(n, m);
    fr(i, m)
    {
        ll a, b, c;
        re(a, b, c);
        if (a == b)
            continue;
        adj1[a].pb({b, c});
        adj2[b].pb({a, c});
    }
    dijkstra1(1);
    dijkstra2(n);
    // dbg(dist1);
    // dbg(dist2);
    ll ans = INF;
    fr(i, n)
    {
        for (auto j : adj1[i + 1])
        {
            if (dist1[i + 1] != INF and dist2[j.ff] != INF)
            {
                ckmin(ans, dist1[i + 1] + (j.ss) / 2 + dist2[j.ff]);
            }
        }
    }

    cout << ans << endl;
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