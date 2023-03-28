#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int sz[N];
void dfs(int node, int par, vector<int> adj[])
{
    sz[node] = 1;
    for (auto &child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node, adj);
        sz[node] += sz[child];
    }
}
 
int main()
{
    int n; cin>>n;
    vector<int> adj[n + 1];
    for (int i = 2; i <= n; i++)
    {
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, 0, adj);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i] - 1 << ' ';
    }
}
