#include <bits/stdc++.h>
using namespace std;
const int MxN = 2e5 + 7;
vector<int> adj[MxN];
vector<int> vis(MxN), par(MxN);

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
    queue<pair<int, int>> q;
    q.push({1, 1});
    vis[1] = 1;
    while (!q.empty())
    {
        auto fr = q.front();
        q.pop();
        for (auto child : adj[fr.first])
        {
            if (vis[child])
                continue;
            vis[child] = 1;
            q.push({child, fr.second + 1});
            par[child] = fr.first;
            if (child == n)
            {
                cout << fr.second + 1 << endl;
                int k = n;
                vector<int> ans;
                while (k != 1)
                {
                    ans.push_back(k);
                    k = par[k];
                }
                ans.push_back(1);
                reverse(ans.begin(), ans.end());
                for (auto &x : ans)
                {
                    cout << x << " ";
                }
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}