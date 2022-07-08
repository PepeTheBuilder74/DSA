/* 3 . DFS 
SC-> O(N)->visited array , O(V+E)->Adjancey list 
TC-> O(V+E)
ASC->O(N)->recursion stack space
*/
const int N = 10e5;
int vis[N];

int DFS(int vertex, vector<int> graph[])
{
    // operations while going inside vertex
    vis[vertex] = 1;
    cout << vertex << " ";
    for (auto child : graph[vertex])
    {
        if (!vis[child])
        {
            DFS(child, graph);
        }
    }

    // operations while coming out of vertex
}

int main()
{
    int vertices, m;
    cin >> vertices >> m;
    vector<int> graph[vertices + 1]; // creating adjency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    for (int i = 1; i <= vertices; i++) // DFS on one node will coverup whole tree so we are looping to cover whole forest
    {
        if (!vis[i])
        {
            DFS(i, graph);
        }
    }
    return 0;
}
