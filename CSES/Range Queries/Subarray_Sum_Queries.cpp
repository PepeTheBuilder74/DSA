#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define each(x, a) for (auto &x : a)
void __solve_testcase(int test_case);
void pre_process();
 
int32_t main() {
    int no_of_testcase = 1;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        __solve_testcase(testcase);
    }
    return 0;
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
