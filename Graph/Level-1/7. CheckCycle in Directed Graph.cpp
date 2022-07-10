/*8.cycle detection in directed graph using DFS

 */
bool DFS(vector<int> adj[], vector<int> &vis, int src, vector<int> &dfsvis)
{
    vis[src] = 1;
    dfsvis[src] = 1;
    for (auto child : adj[src])
    {

        if (!vis[child])
        {
            if (DFS(adj, vis, child, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[child])
        {
            return true;
        }
    }
    dfsvis[src] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfsvis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (DFS(adj, vis, i, dfsvis))
            {
                return true;
            }
        }
    }
    return false;
}

/* 11. Detect Cycle in directed graph using BFS (Kahn's ALgoithm )

1. find the topo sort .
2. if we are able to find the topo sort , it means there is no cycle in graph since topo sort is only possible for DAG .
TC->O(V+E)
SC->O(N)->Indegree , O(N)->Queue
ASC->O(1)

*/
bool isCyclic(int V, vector<int> adj[])
{

    // find degree of each vertices

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto child : adj[i])
        {
            indegree[child]++;
        }
    }
    queue<int> q;
    int cnt = 0;

    // push element  with zero degree in queue

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // normal toposort
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    // if toposort is found then false
    if (cnt == V)
    {
        return false;
    }
    else
        return true;
}