#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define int long long
template<typename node, typename update>
struct segtree {
    vector<node> t;
    vector<update> upds;
    vector<bool> lazy;
    int size;
 
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        t.assign(2 * size, node());
        upds.assign(2 * size, update());
        lazy.assign(2 * size, 0);
    }
 
    inline void propogate(int x, int lx, int rx) {
        if (lazy[x]) {
            int mid = (lx + rx) / 2;
            apply(2 * x + 1, upds[x], lx, mid);
            apply(2 * x + 2, upds[x], mid + 1, rx);
            lazy[x] = 0;
            upds[x] = update();
        }
    }
 
    inline void apply(int x, update &val, int lx, int rx) {
        if (lx != rx) {
            lazy[x] = 1;
            upds[x].combine(val, lx, rx);
        }
        val.apply(t[x], lx, rx);
    }
 
    template<typename T>
    void build(T &v, int x, int lx, int rx) {
        if (rx == lx) {
            if (lx < (int) v.size()) t[x] = v[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid + 1, rx);
        t[x].merge(t[2 * x + 1], t[2 * x + 2]);
    }
 
    node query(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return node();
        if (l <= lx and rx <= r) return t[x];
        propogate(x, lx, rx);
        int mid = (lx + rx) / 2;
        node L, R, ans;
        L = query(l, r, 2 * x + 1, lx, mid);
        R = query(l, r, 2 * x + 2, mid + 1, rx);
        ans.merge(L, R);
        return ans;
    }
 
    void rupd(int l, int r, update &v, int x, int lx, int rx) {
        if (lx > r || rx < l) return;
        if (l <= lx and rx <= r) {
            apply(x, v, lx, rx); return;
        }
        propogate(x, lx, rx);
        int mid = (lx + rx) / 2;
        rupd(l, r, v, 2 * x + 1, lx, mid);
        rupd(l, r, v, 2 * x + 2, mid + 1, rx);
        t[x].merge(t[2 * x + 1], t[2 * x + 2]);
    }
 
 
    int find_first(int l, int val, int x, int lx, int rx, node &prev) {
        if (rx < l) return size;
        if (l <= lx) {
            node curr;
            curr.merge(prev, t[x]);
            if (!curr.check(val)) {
                swap(prev, curr);
                return size;
            }
            if (lx == rx) return lx;
        }
        propogate(x, lx, rx);
        int mid = (lx + rx) / 2;
        int ans = find_first(l, val, 2 * x + 1, lx, mid, prev);
        if (ans != size) return ans;
        return find_first(l, val, 2 * x + 2, mid + 1, rx, prev);
    }
 
    int find_last(int r, int val, int x, int lx, int rx, node &prev) {
        if (r < lx) return -1ll;
        if (rx <= r) {
            node curr;
            curr.merge(prev, t[x]);
            if (!curr.check(val)) {
                swap(prev, curr);
                return -1ll;
            }
            if (lx == rx) return lx;
        }
        propogate(x, lx, rx);
        int mid = (lx + rx) / 2;
        int ans = find_last(r, val, 2 * x + 2, mid + 1, rx, prev);
        if (ans == -1) ans = find_last(r, val, 2 * x + 1, lx, mid, prev);
        return ans;
    }
 
    template<typename T>
    void build(T &v) {
        build(v, 0, 0, size - 1);
    }
 
    node query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }
 
    void rupd(int l, int r, update val) {
        rupd(l, r, val, 0, 0, size - 1);
    }
 
    int find_first(int l, int val) {
        node prev = node();
        return find_first(l, val, 0, 0, size - 1, prev);
    }
 
    int find_last(int r, int val) {
        node prev = node();
        return find_last(r, val, 0, 0, size - 1, prev);
    }
};

struct node {
    int sum = 0;
    node() : node(0) {}
    node(int val) {
        sum = val;
    }
    inline void merge(node &l, node &r) {
        sum = (l.sum  + r.sum);
    }
    bool check(int x) {
        return false;
    }
};
struct update
{
    // bsdk isko dekhna neutral values matt fuckup kar lode
    int type=1,val=0;
    update() {}
    update(int v,int t) {
        val=v;
        type=t;
    }
    // combine the current my_update with the other my_update (seekeynotes)
    inline void combine(update &other, const int32_t &tl, const int32_t &tr)
    {   
        assert(other.type!=0);
        if(other.type==1){
            val+=other.val;
        }
        else{
            val=other.val;
            type=2;
        }
    }
    // store the correct information in the my_nodex
    void apply(node & x, const int32_t & tl, const int32_t & tr)
    {
        if(type==1){
            x.sum+=val*(tr-tl+1);
        }
        else{
            x.sum=val*(tr-tl+1);
        }
    }
};
int32_t main(){
    int n,q;    cin>>n>>q;
    vector<int> a(n);    for(int i=0;i<n;i++) cin>>a[i];
    segtree<node,update> s;
    s.init(n);
    s.build(a);
    while(q--){
        int type;   cin>>type; int l,r; cin>>l>>r; l--;r--;
        if(type==1){
            int val; cin>>val;
            s.rupd(l,r,update(val,1));
        }
        else if(type==2){
            int val; cin>>val;
            s.rupd(l,r,update(val,2));
        }
        else{
            cout<<s.query(l,r).sum<<endl;
        }
    }
    return 0;
}
