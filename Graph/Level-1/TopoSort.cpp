/* 9. Topo sort using BFS ( Kahn's Algorithm )
ONLY POSSIBLE FOR DAG
1.Go to src which is  dependent on  nodes and push it at the top of stack .Vertix which is least dependent on other node will come first.
2.Find indegree of all the node and store it in array .
3.Create queue and push element whose indegree are zero .
4.EK element pe jaake BFS lagao aur uska jo bhi adjacent hoga us element ka  indegree  subract by 1 kardo .
5.Repeat 4 until indegree of the element becomes zero and then push that element in queue.
6.TC : O(V+E)
7.SC : O(N)-->Indegree array , O(N)-->queue
8.ASC : O(1)

*/

vector<int> topo(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

/* 10. Topo sort using DFS

ONLY POSSIBLE FOR DAG
1.Go to src which is  dependent on  nodes and push it at the top of stack
2.vertix which is least dependent on other node will come first.
3.TC : O(V+E)
4.SC : O(N)-->vis array , O(N)-->stack
5.ASC : O(N)-->recurssion calls

*/

void dfs(vector<int> adj[], vector<int> &vis, stack<int> &s, int src)
{
    vis[src] = 1;

    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            dfs(adj, vis, s, child);
        }
    }
    s.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0), ans;
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(adj, vis, s, i);
    }
    while (!s.empty())
    {
        int x = s.top();
        ans.push_back(x);
        s.pop();
    }

    return ans;
}