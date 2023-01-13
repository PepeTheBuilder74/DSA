#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
vector<int> vis(MxN, 0);

void dfs(int node)
{
    /*Take action on vertex after entering the vertex
     */
    vis[node] = 1;
    for (auto child : adj[node])
    {
        /*Take action on Child before entering the child */
        if (!vis[child])
        {
            dfs(child);
        }
        /*Take action on Child after exiting  from the child */
    }
    /*Take action on vertex after exiting from the vertex
     */
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}