#include <bits/stdc++.h>
using namespace std;

const int MxN = 2e5 + 5;
vector<int> adj[MxN];
vector<int> subSum(MxN, 0), cntEven(MxN, 0);

/*Given Q queries, Q<=1e5
  In Each query given V
  Print Subtree sum of V and cnt of even numbers in subtree sum of V
*/

void dfs(int node, int par = -1)
{
    /*Take action on vertex after entering the vertex
     */
    if (node % 2 == 0)
        cntEven[node]++;
    subSum[node] += node;
    for (auto child : adj[node])
    {

        /*Take action on Child before entering the child */
        if (child == par)
            continue;
        dfs(child, node);

        subSum[node] += subSum[child];
        cntEven[node] += cntEven[child];
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

    int q;
    cin >> q;
    while (q--)
    {
        int v;
        cin >> v;
        cout << subSum[v] << " " << cntEven[v] << endl;
    }
}