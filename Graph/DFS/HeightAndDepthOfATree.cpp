#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
vector<int> height(MxN, 0), depth(MxN, 0);

void dfs(int node, int par = -1)
{
    /*Take action on vertex after entering the vertex
     */
    for (auto child : adj[node])
    {

        /*Take action on Child before entering the child */
        if (child == par)
            continue;

        depth[child] = depth[node] + 1;

        dfs(child, node);

        height[node] = max(height[node], height[child] + 1);
        /*Take action on Child after exiting  from the child */
    }
    /*Take action on vertex after exiting from the vertex
     */
}

int main()
{
    int n, m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        cout << height[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        cout << depth[i] << " ";
    }
    cout << endl;
}