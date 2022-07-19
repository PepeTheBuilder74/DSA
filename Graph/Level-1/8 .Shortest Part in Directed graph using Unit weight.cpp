#include <bits/stdc++.h>
using namespace std;

/*12.Shortest Part in Directed graph using Unit weight

1.Create a distance array to store the distance of all nodes form src node and init. with INT_MAX
2.Through BFS visit all its adjacent node and compare its previous value in distance array and if it is small then update it.
3.TC->O(V+E)
4.SC->O(N)-->queue +O(N)-->Dis
5.ASC->O(1)

*/
void BFS(vector<int> adj[], int N, int src)
{
    // create a distance array to store all the distances
    int dist[N];

    // initialize it with INT_MAX
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;

    // creating a queue and pushing the source
    queue<int> q;
    q.push(src);

    // distance of src from src will be equal to 0
    dist[src] = 0;

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        // visit all adjacent node of a node
        for (auto child : adj[node])
        {
            // if dist of child from node +1 is less than in dist array then change the distance in distance array , here distance array is working as a visited array
            if (dist[child] + 1 < dist[node])
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    // distance of all the nodes from src node
    for (int i = 0; i < N; i++)
        cout << dist[i] << " ";
}