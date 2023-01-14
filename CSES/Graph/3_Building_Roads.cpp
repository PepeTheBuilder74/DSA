#include <bits/stdc++.h>
using namespace std;
const int MxN = 2e5 + 7;
vector<int> adj[MxN];
vector<int> vis(MxN);
void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs(child);
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
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i + 1 < ans.size(); i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}