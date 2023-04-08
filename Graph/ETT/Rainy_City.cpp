#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define nl "\n"
#define ll long long int
#define rall(a) (a).rbegin(), (a).rend()
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

template <typename T> void ckmin(T &a, const T &b){ a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }
template <class T1, class T2> void re(pair<T1, T2> &p);
template <class T> void re(vector<T> &a);
template <class T, size_t SZ> void re(array<T, SZ> &a);
template <class T> void re(T &x) { cin >> x; }
void re(double &x) { string t;re(t); x = stod(t);}
template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first);  re(rest...); } 
template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.ff, p.ss); }
template <class T> void re(vector<T> &a) {for (int i = 0; i < sz(a); i++) re(a[i]); }
template <class T, size_t SZ>void re(array<T, SZ> &a) { for (int i = 0; i < SZ; i++)      re(a[i]); }
template <class T>
void write(T x) { cout << x << " "; }
template <class T> void writen(T x) { cout << x << nl; }
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >;
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//  random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}
const int MxN = 2000100;
const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;
const int N = 2e5 + 5;
const ll INF = 1e18;
// pbds = find_by_value(), order_of_key()

void __solve_testcase(int test_case);
void pre_process();
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre_process();
 
    int no_of_testcase = 1;
    // cin >> no_of_testcase;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        // cout << "Case #" << testcase << ": ";
        __solve_testcase(testcase);
    }
    return 0;
}
 
void pre_process() {

}
vector<int>adj[mxn];
int tin[mxn],tout[mxn],timer=1;
int par[mxn][20];
void dfs(int u,int p){
    tin[u]=timer++;
    par[u][0]=p;
    for(int i=1;i<20;i++){
        par[u][i]=par[par[u][i-1]][i-1];
    }
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
    }
    tout[u]=timer++;
}
bool is_ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int LCA(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=19;i>=0;i--){
        if(!is_ancestor(par[u][i],v)){
            u=par[u][i];
        }
    }
    return par[u][0];
    
}
template <class T>
class BIT
{
    static_assert(is_integral<T>::value, "Integer required");

private:
    const size_t N;
    vector<T> data;

public:
    // Binary indexed tree or fenwick tree
    // O (log n) all operations except order
    // order complexity - O (log n)
    // 1 based indexing
    BIT() : N(0) {}
    BIT(const size_t _N) : N(_N), data(_N + 1) {}

    size_t size()
    {
        return N;
    }
    // sum of [1, idx]
    // range sum query
    T sum(size_t idx)
    {
        T ans = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            ans += data[idx];
        }
        return ans;
    }
    T sum(size_t l, size_t r)
    {
        return sum(r) - sum(l - 1);
    }

    // Point update
    void add(size_t idx, T val)
    {
        for (; idx <= N; idx += (idx & -idx))
        {
            data[idx] += val;
        }
    }

    // Range update
    void range_add(size_t l, size_t r, T val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    template <class OStream>
    friend OStream &operator<<(OStream &os, BIT &bit)
    {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.N; i++)
        {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
    int order(T sum)
    {
        // find kth smallest element
        // if doesn't exists return 0
        int mxind = 0;
        while (1 << (mxind + 1) <= N)
            mxind++;
        int pos = 0;
        while (mxind >= 0)
        {
            if (pos + (1 << mxind) <= N && data[pos + (1 << mxind)] < sum)
            {
                pos += (1 << mxind);
                sum -= data[pos];
            }
            mxind--;
        }
        return pos + 1;
    }
    // You can either do one of the following
    // 1. Range update and point query
    // 2. Point update and range query
};
void __solve_testcase(int test_case) {
    int n,m;
    re(n,m);
    fr(i,n-1){
        int u,v;
        re(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    tin[0]=-1;
    tout[0]=1e9;
    BIT<ll>bit(timer);
    fr(i,m){
        int node1,node2,val;
        re(node1,node2,val);
        int lca=LCA(node1,node2);
        bit.add(tin[node1],val);
        bit.add(tin[node2],val);
        bit.add(tin[lca],-val);
        if(par[lca][0]!=0){
            bit.add(tin[par[lca][0]],-val);
        }
        cout<<"node1 "<<node1<<' '<<tin[node1]<<' '<<tout[node1]<<nl;
        cout<<"node2 "<<node2<<' '<<tin[node2]<<' '<<tout[node2]<<nl;
        cout<<"lca "<<lca<<' '<<tin[lca]<<' '<<tout[lca]<<nl;
        cout<<par[lca][0]<<' '<<tin[par[lca][0]]<<' '<<tout[par[lca][0]]<<nl;
        cout<<i<<' '<<bit<<nl;
    }
    ll mx=INF,node=0;
    for(int i=1;i<=n;i++){
        if(bit.sum(tin[i],tout[i])<mx){
            mx=bit.sum(tin[i],tout[i]);
            node=i;
        }
    }
    cout<<node<<nl;

}