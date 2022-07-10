/*6.Check if a graph is bipartite using BFS
 */
bool checkBipartite(vector<int> &color, vector<int> adj[], int V, int src)
{
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (color[child] == -1)
            {
                color[child] = 1 - color[node];
                q.push(child);
            }
            else if (color[child] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {

        if (color[i] == -1)
        {
            if (!checkBipartite(color, adj, V, i))
            {
                return false;
            }
        }
    }
    return true;
}

// 7. Check if a graph is bipatrite using DFS

bool checkBipartite(vector<int> &color, vector<int> adj[], int V, int src)
{
    if (color[src] == -1)
    {
        color[src] = 1;
    }
    for (auto child : adj[src])
    {
        if (color[child] == -1)
        {
            color[child] = 1 - color[src];
            if (!checkBipartite(color, adj, V, child))
            {
                return false;
            }
        }
        else if (color[child] == color[src])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {

        if (color[i] == -1)
        {
            if (!checkBipartite(color, adj, V, i))
            {
                return false;
            }
        }
    }
    return true;
}