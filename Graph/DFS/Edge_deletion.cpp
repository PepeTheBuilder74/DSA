#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
int val[MxN], subSum[MxN];
void dfs(int node, int par = -1)
{
    /*Take action on vertex after entering the vertex
     */
    subSum[node] += val[node];
    for (auto child : adj[node])
    {
        /*Take action on Child before entering the child */
        if (child == par)
            continue;
        dfs(child, node);
        subSum[node] += subSum[child];
        /*Take action on Child after exiting  from the child */
    }
    /*Take action on vertex after exiting from the vertex
     */
}

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    const int MOD = 1e9 + 7;
    dfs(1);
    int res = 0;
    int total = subSum[1];
    for (int i = 2; i <= n; i++)
    {
        res = max(res, (total - subSum[i]) * subSum[i]);
    }
    return res % MOD;
}