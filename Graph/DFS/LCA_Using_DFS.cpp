#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
vector<int> par(MxN, 0);

void dfs(int node, int pa = -1)
{
    /*Take action on vertex after entering the vertex
     */
    par[node] = pa;
    for (auto child : adj[node])
    {
        /*Take action on Child before entering the child */
        if (child == pa)
            continue;
        dfs(child, node);
        /*Take action on Child after exiting  from the child */
    }
    /*Take action on vertex after exiting from the vertex
     */
}
vector<int> getPath(int vertex)
{
    vector<int> ans;
    while (vertex != -1)
    {
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int z;
    cin >> z;
    for (int i = 1; i <= z; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int m, n;
    cin >> m >> n;
    vector<int> path_m = getPath(m);
    vector<int> path_n = getPath(n);
    int sz = min(path_m.size(), path_n.size());
    int lca = -1;
    for (int i = 0; i < sz; i++)
    {
        if (path_m[i] != path_n[i])
        {
            break;
        }
        lca = path_m[i];
    }
    cout << lca << endl;
}