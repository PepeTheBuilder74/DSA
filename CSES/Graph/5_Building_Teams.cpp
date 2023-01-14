#include <bits/stdc++.h>
using namespace std;
const int MxN = 2e5 + 7;
int n, m;
vector<int> adj[MxN];
vector<int> color(MxN, -1);
bool checkBipar(int node)
{
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int child : adj[fr])
        {
            if (color[child] == -1)
            {
                color[child] = !color[fr];
                q.push(child);
            }
            else if (color[child] == color[fr])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{

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
        if (color[i] == -1)
        {
            if (!checkBipar(i))
            {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << color[i] + 1 << " ";
    }
    cout << "\n";
}