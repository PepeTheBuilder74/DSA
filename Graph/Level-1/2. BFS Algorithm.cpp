/* 2. BFS   */

const int N = 10e5;
int vis[N];

int bfs(int parent, vector<int> graph[])
{
    queue<int> q;
    q.push(parent);
    vis[parent] = 1;
    while (!q.empty())
    {
        int cur_ver = q.front();
        cout << cur_ver << " ";
        q.pop();
        for (auto child : graph[cur_ver])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}
int main()
{
    int vertices, m;
    cin >> vertices >> m;
    vector<int> graph[vertices + 1];
    for (int i = 0; i < vertices; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    // In order to apply bfs in full forest, bfs in one node will let us visit whole tree or graph in one go.

    for (int i = 1; i <= vertices; i++)
    {
        if (!vis[i])
        {
            bfs(i, graph);
        }
    }
    return 0;
}
