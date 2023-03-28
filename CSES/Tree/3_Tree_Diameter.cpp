#include <bits/stdc++.h>
using namespace std;

// find the maximum depth node of a tree
// then find the maximum depth node of the tree from that node
int  main()
{
    int n; cin>>n;
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;  cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n + 1, 0);
    function<void(int, int)> dfs = [&](int node, int par)
    {
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            depth[child] = 1 + depth[node];
            dfs(child, node);
        }
    };
    dfs(1, -1);
    int maxi = 0, node = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > maxi)
        {
            maxi = depth[i];
            node = i;
        }
        depth[i] = 0;
    }
    dfs(node, -1);
    for (auto &x : depth)
        maxi = max(maxi, x);
    cout << maxi << '\n';
}
