/* 9. Topo sort using BFS ( Kahn's Algorithm )

ONLY POSSIBLE FOR DAG and MULTIPLE TOPO SORT IS POSSIBLE 
1.Find indegree of all the node and store it in array .
2.Create queue and push element whose indegree are zero .
3.EK element pe jaake BFS lagao aur uska jo bhi adjacent hoga us element ka  indegree  subract by 1 kardo .
4.Repeat 4 until indegree of the element becomes zero and then push that element in queue.
5.TC : O(V+E)
6.SC : O(N)-->Indegree array , O(N)-->queue
7.ASC : O(1)

*/

vector<int> topo(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);    // Find the degree of all the nodes 
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < N; i++)  // Nodes with 0 degree are pushed down in queue because those elements will always come first in topo sort .
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;               // topo sort array which we will return 
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);        // pushing the top node in our topo sort 
        for (auto it : adj[node])   // find all the child of the top node and reduce the degree of child by 1 each time we come across child
        {
            indegree[it]--;         
            if (indegree[it] == 0)  // whenever degree is equal to zero we will push down that child/node into queue
            {
                q.push(it);
            }
        }
    }
    return topo;                   // returning out topo sort array , we might have different topo sort for same graph 
}

/* 10. Topo sort using DFS

ONLY POSSIBLE FOR DAG
1.Go to node which is  dependent on  nodes  and push it at the top of stack
2.Vertix which is least dependent on other node will come first in topo sort array but last in stack 
3.In general go to depth first and add that node in the depth into stack and while returning add another nodes 
4.TC : O(V+E)
5.SC : O(N)-->vis array , O(N)-->stack
6.ASC : O(N)-->recurssion calls

*/

// Do simple DFS just add src node while returning from DFS 
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
    // Only difference from  DFS code 
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
    
    // Element at top of stack are least dependent on other nodes or least degree so they will be first in our topo sort array
    while (!s.empty())
    {
        int x = s.top();
        ans.push_back(x);
        s.pop();
    }

    return ans;
}

/*
Note: Here, we can also use vector instead of the stack. If the vector is used then print the elements in reverse order to get the topological sorting.

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling,
ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in make files,
data serialization, and resolving symbol dependencies in linkers. 
*/
