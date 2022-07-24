#include <bits/stdc++.h>
using namespace std;

/*14. Dijkstras's Algorithm (Shortest Path in Directed graph)


1. First of all, we will mark all vertex as unvisited vertex
2. Then, we will mark the source vertex as 0 and all other vertices as infinity
3. Consider source vertex as current vertex
4. Calculate the path length of all the neighboring vertex from the current vertex by adding the weight of the edge in the current vertex
5. Now, if the new path length is smaller than the previous path length then replace it otherwise ignore it
6. Mark the current vertex as visited after visiting the neighbor vertex of the current vertex
7. Select the vertex with the smallest path length as the new current vertex and go back to step 4.
8. Repeat this process until all the vertex are marked as visited.
9. TC-> O(V^2) but with min heap it is (V+ ElogV)
10. SC->O(V)-->PQ , O(V)-->Visited , o(V)-->Distance
11. ASC->O(1)
                                                  Refer to luv video

*/

// comparator class to sort the pq in ascending order of second element of pair
class cmp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

// main code
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int N, vector<vector<int>> adj[], int S)
    {
        // distance array
        vector<int> dist(N);

        // initialize it with INT_MAX
        for (int i = 0; i < N; i++)
            dist[i] = INT_MAX;

        // creating a min heap with comparator function , we can also use set and we dont need to use visited array with set.
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        // pushing source with distance 0 ,since distance from source to source will be 0
        pq.push({S, 0});

        // distance of src from src will be equal to 0
        dist[S] = 0;

        vector<int> vis(N, 0);

        while (!pq.empty())
        {

            int prevNode = pq.top().first;
            int distanceFromSourceToPrevNode = pq.top().second;
            pq.pop();
            if (vis[prevNode])
                continue;
            vis[prevNode] = 1;

            for (auto child : adj[prevNode])
            {
                int nextNode = child[0];
                int distanceToReachChildFromPrevNode = child[1];
                if (distanceFromSourceToPrevNode + distanceToReachChildFromPrevNode < dist[nextNode])
                {
                    dist[nextNode] = distanceFromSourceToPrevNode + distanceToReachChildFromPrevNode;
                    pq.push({nextNode, dist[nextNode]});
                }
            }
        }
        return dist;
    }
};
