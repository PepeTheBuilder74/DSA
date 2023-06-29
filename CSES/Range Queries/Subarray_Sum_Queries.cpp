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

template<typename T>
class segtree {
public:
// 0 based indexing
// def= default value
	vector<T> t;
	int n;
	T def;
	function<T(T, T)>merge;
	void build(int _n, T _def, function<T(T, T)> _fx) {
		n = _n; def = _def;merge = _fx;
		t.assign(n * 2, def);
		for(int i = n - 1; i; i--) t[i] =merge(t[i * 2], t[i * 2 + 1]);
	}
	void build(const vector<ll>& a, T _def, function<T(T, T)> _fx) {
		n = a.size(); def = _def;merge = _fx;
		t.assign(n * 2, def);
		for(int i=0;i<n;i++) t[i + n] = T(a[i]);
		for(int i = n - 1; i; i--) t[i] =merge(t[i * 2], t[i * 2 + 1]);
	}
	void update(int i, T v) {
		for(t[i += n] = T(v); i > 1; ) {
			i /= 2;
			t[i] =merge(t[i * 2], t[i * 2 + 1]);
		}
	}
	// this query is made on [l, r)
	T query(int l, int r) {
		T lans = def, rans = def;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l % 2) lans =merge(lans, t[l++]);
			if(r % 2) rans =merge(t[--r], rans);
		}
		return merge(lans, rans);
	}
	void debug() {
        cout<<"[ ";
		each(x, t) cout << x << " , ";
        cout<<"]";
        cout << endl;
	}
};
struct node {
    ll total_sum=0,pref_max=0,suff_max=0,seg_max=0;
    node(ll x) {
        total_sum=x;
        pref_max=suff_max=seg_max=max(0LL,x);
    }
    // default value
    node() {
        total_sum=0;
        pref_max=suff_max=seg_max=0;
    }
};
void __solve_testcase(int test_case) {
    int N,Q;cin>>N>>Q;
    vector<ll> a(N);  each(x,a) cin>>x;
   
    auto merge=[](node a,node b){
       node c;
       c.total_sum=a.total_sum+b.total_sum;
       c.pref_max=max(a.pref_max,a.total_sum+b.pref_max);
       c.suff_max=max(b.suff_max,b.total_sum+a.suff_max);
       c.seg_max=max({a.seg_max,b.seg_max,a.suff_max+b.pref_max});
       return c;
    };
    segtree<node> st;
    st.build(a,node(0),merge);
    while(Q--){
        int pos, val;cin>>pos>>val;
        pos--;
        st.update(pos, val);
        cout<<st.query(0,N).seg_max<<nl;
    }
}