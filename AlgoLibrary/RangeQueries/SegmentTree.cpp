struct node
{
    int val;
    node(int x)
    {
        val = x;
    }
    // default value
    node()
    {
        val = 0;
    }
};
template <typename T>
class segtree
{
public:
    // 0 based indexing
    // def= default value
    vector<T> t;
    int n;
    T def;
    function<T(T, T)> merge;
    void build(int _n, T _def, function<T(T, T)> _fx)
    {
        n = _n;
        def = _def;
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void build(vector<int> &a, T _def, function<T(T, T)> _fx)
    {
        n = a.size();
        def = _def;
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = 0; i < n; i++)
            t[i + n] = T(a[i]);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void update(int i, int v)
    {
        for (t[i += n] = T(v); i > 1;)
        {
            i /= 2;
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
        }
    }
    // this query is made on [l, r)
    T query(int l, int r)
    {
        T lans = def, rans = def;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l % 2)
                lans = merge(lans, t[l++]);
            if (r % 2)
                rans = merge(t[--r], rans);
        }
        return merge(lans, rans);
    }
    void debug()
    {
        cout << "[ ";
        each(x, t) cout << x << " , ";
        cout << "]";
        cout << endl;
    }
};

int main(){
   auto merge=[](node a,node b){
       node c;
       // merge logic
       return c;
   };
}
