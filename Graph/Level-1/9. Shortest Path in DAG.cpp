#include <bits/stdc++.h>
using namespace std;

/*13. Shortest Path in DAG
1. Find TopoSort of the graph
2. Create a distance array and init it with INT_MAX
3. Pick the top element of the stack and visit all its child (only if dist[node] != INF ) and update the distance accordingly.
4. TC->O(V+E) --> topo sort , O(V+E)-->shortest path
5. SC-> O(N)-->Stack , O(N)-->visited array , O(N)-->Distance array
6. ASC->O(V)-->recur. stack space

*/

// Finding Topo Sort
void findTopoSort(vector<pair<int, int>> adj[], int src, stack<int> &st, vector<int> &vis)
{
    vis[src] = 1;
    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            findTopoSort(adj, child, st, vis);
        }
    }
    st.push(src);
}

void findShortestPath(vector<pair<int, int>> adj[], int src, int N)
{
    vector<int> vis(N, 0);
    stack<int> st;

    // Finding TopoSort
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            findTopoSort(adj, i, st, vis);
        }
    }

    // creating distance array
    int dist[N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX:
    }

    // distance from src to src will be 0
    dist[src] = 0;

    // while stack is not empty
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // If the node has not been reached previously,sort of calc the relative distance from source only
        if (dist[node] != INT_MAX)
        {
            for (auto child : adj[node])
            {
                // codition of minimising distance
                if (dist[node] + child.second < dist[child.first])
                {
                    // updating distance
                    dist[child.first] = dist[node] + child.second;
                }
            }
        }
    }

    // Printing the distance array
    for (int i = 0; i < N; i++)
    {
        cout << (dist[i] == INT_MAX ? "INF" : dist[i]);
    }
}

/*
3 Methods to solve this-

  1. Using Bellman-Ford [ TC = O(VE) ]
  2. Using Dijkstra's Algorithm [ TC = O(E + Vlog(V)) ]
  3, Topological Sort [ TC = O(V + E) ]

Why Topological sorting ?
   lets say you want to do it using DFS
   yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and lets say its 7 and as it is DFS then its
   obvious that you also have updated all the nodes in its segment of DFS call . now you have reached to the same node from different dfs() call and now the distance
   is 4 , so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , you now again have to do the
   same so that its updated with new min distance. Same is the scenario for the simple BFS approach.

   This multiple time calling DFS/BFS degrades the Time Complexity, hence Topological Ordering save you from that overhead as you already know which nodes will
   come after the current node , so you keep on updating it .

*/