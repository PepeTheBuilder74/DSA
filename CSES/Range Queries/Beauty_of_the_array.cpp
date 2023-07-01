#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define each(x, a) for (auto &x : a)
void __solve_testcase(int test_case);
void pre_process();

int32_t main()
{
    int no_of_testcase = 1;
    cin >> no_of_testcase;
    for (int testcase = 1; testcase <= no_of_testcase; testcase++)
    {
        __solve_testcase(testcase);
    }
    return 0;
}
/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/

// example: addition: identity element is 0

// a + 0 = a or 0 + a = a

// min(x,INF) = x
const ll INF = 1e18;
struct my_node
{
    ll v = 0; // 4
    ll total_sum = 0, pref_max = -INF, suff_max = -INF, seg_max = -INF;
    // use more variables if you want more information
    // these default values should be identity_element
    my_node() {}
    my_node(ll val)
    {
        v = val; // 5
        total_sum = val;
        pref_max = val;
        suff_max =val;
        seg_max = val;
    }
    void merge(const my_node &l, const my_node &r)
    { // store the thing you wanna query

        total_sum = l.total_sum + r.total_sum;
        pref_max = max(l.pref_max, l.total_sum + r.pref_max);
        suff_max = max(r.suff_max, r.total_sum + l.suff_max);
        seg_max = max({l.seg_max, r.seg_max, l.suff_max + r.pref_max});
        // if we wanted the maximum, then we would do
        // like v = max(l.v,r.v)
    }
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct my_update
{
    ll v = 0; // 4
              // use more variables if you want more information
              // these default values should be identity_transformation
    my_update() {}
    my_update(ll val)
    {
        v = val; // 5
    }
    // combine the current my_update with the other my_update (see keynotes)
    void combine(my_update &other, const int32_t &tl, const int32_t &tr)
    {
       v=other.v;
    }
    // store the correct information in the my_node x
    void apply(my_node &x, const int32_t &tl, const int32_t &tr)
    {
        x.total_sum = (tr - tl + 1) * v;
        if(v>=0){
            x.pref_max=x.suff_max=x.seg_max=x.total_sum;
        }
        else{
            x.pref_max=x.suff_max=x.seg_max=v;
        }
    }
};

template <typename node, typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }

    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
        {
            return identity_element;
        }
        if (tl >= l && tr <= r)
        {
            return t[v];
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};
void __solve_testcase(int test_case)
{
    int N, Q;
    cin >> N;
    vector<ll> a(N);
    each(x, a) cin >> x;
    cin >> Q;
    segtree<my_node, my_update> st(N);
    st.build(a);

    while (Q--)
    {
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (type == 1)
        {
            int val;
            cin >> val;
            st.rupd(l, r, my_update(val));
        }
        else
        {
            cout << st.query(l, r).seg_max << endl;
        }
    }
}