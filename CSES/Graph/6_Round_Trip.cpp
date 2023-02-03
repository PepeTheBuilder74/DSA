#include <bits/stdc++.h>
using namespace std;
const int MxN = 2e5 + 7;
vector<int> adj[MxN];
vector<int> vis(MxN), par(MxN);

void dfs(int node, int p = -1)
{
    par[node] = p;
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (child == p)
            continue;
        if (vis[child])
        {
            vector<int> ans;
            ans.push_back(child);
            int k = node;
            ans.push_back(k);
            while (node != child)
            {
                node = par[node];
                ans.push_back(node);
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (auto &x : ans)
                cout << x << " ";

            exit(0);
        }
        else
        {
            dfs(child, node);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << "IMPOSSIBLE\n";
}