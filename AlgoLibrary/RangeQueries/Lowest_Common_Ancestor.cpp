struct ancestors {
    int n, level, root, tin;
    vector <vector<int>> st;
    vector<vector<int>> adj;
    vector <int> p, d, t;
 
    ancestors() {}
    ancestors(int n, int root, vector<vector<int>> &adj) : n(n), root(root), adj(adj) {
    tin = 0;
        level = log2(n) + 1;
        st.assign(n + 1, vector <int> (level, -1));
        p.assign(n + 1, 0);
        d.assign(n + 1, 0);
        t.assign(n + 1, 0);
        fillst();
    }
 
    void findpar(int x, int par) {
        p[x] = par;
        for (auto it : adj[x]) {
           if(it!=par){
            d[it] = d[x] + 1;
            findpar(it, x);
           } 
        }
        t[x] = tin++;
    }
 
    void fillst() {
        findpar(root, 0);
        for (int j = 0; j < level; j++) {
            for (int i = 1; i <= n; i++) {
                if (j == 0) st[i][j] = p[i];
                else if (st[i][j - 1] != -1) st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }
    }
 
    int kth(int x, int k) {
        for (int i = level - 1; i >= 0; i--) {
            if (k >= (1 << i)) {
                x = st[x][i];
                k -= (1 << i);
            }
        }
        return x;
    }
 
    int lca(int x, int y) {
        if (d[y] < d[x]) swap(x, y);
        y = kth(y, d[y] - d[x]);
        if (x == y) return x;
 
        for (int i = level - 1; i >= 0; i--) {
            if (st[x][i] != -1 && st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }
        // 1 as root always  
        return st[x][0];
    }
 
    int distance(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }
};