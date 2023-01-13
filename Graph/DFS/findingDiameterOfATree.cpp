#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
vector<int> depth(MxN, 0);

void dfs(int node, int par = -1)
{
    /*Take action on vertex after entering the vertex
     */
    for (auto child : adj[node])
    {
        /*Take action on Child before entering the child */
        if (child == par)
            continue;
        depth[child] = 1 + depth[node];
        dfs(child, node);
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
    /*
    1.Find max depth of tree from root node
    2.That node is one end of diameter -> let this nod be X
    3.Treat X as root node and find the largest depth node
    4.That node is second end of Diameter and depth is our diameter size
    */

    dfs(1);
    int mx_depth = -1, max_d_node = -1;
    for (int i = 1; i <= 14; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }
    dfs(max_d_node);
    mx_depth = -1;
    for (int i = 1; i <= 14; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }
    cout << mx_depth;
}