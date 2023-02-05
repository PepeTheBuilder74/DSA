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

void dfs1(int node, vector<pair<ll, ll>> edges[], vb &vis)
{
    vis[node] = true;
    for (auto x : edges[node])
    {
        if (!vis[x.ff])
        {
            dfs1(x.ff, edges, vis);
        }
    }
}
void dfs2(int node, vector<ll> adj[], vb &vis)
{
    vis[node] = true;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs2(x, adj, vis);
        }
    }
}

void solve()
{
    int n, m;
    re(n, m);
    vector<pair<ll, ll>> edges[n + 1];
    vll dist(n + 1, -INF);
    vll adj[n + 1];
    fr(i, m)
    {
        ll a, b, c;
        re(a, b, c);
        edges[a].pb({b, c});
        adj[b].pb(a);
    }
    dist[1] = 0;
    fr(i, n - 1)
    {
        fr(j, n)
        {
            for (auto x : edges[j + 1])
            {
                if (dist[j + 1] != -INF && dist[j + 1] + x.ss > dist[x.ff])
                {
                    dist[x.ff] = max(dist[x.ff], dist[j + 1] + x.ss);
                }
            }
        }
    }
    bool neg = false;
    vb vis1(n + 1, false), vis2(n + 1, false);
    // dbg(dist);
    dfs1(1, edges, vis1);
    dfs2(n, adj, vis2);
    fr(i, n)
    {
        for (auto x : edges[i + 1])
        {
            if (dist[i + 1] + x.ss > dist[x.ff] && vis1[x.ff] && vis2[x.ff])
            {
                neg = true;
            }
        }
    }
    // dbg(dist);
    if (neg)
    {
        cout << -1 << endl;
        return;
    }

    cout << dist[n] << endl;
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