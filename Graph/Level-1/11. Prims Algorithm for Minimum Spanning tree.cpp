#include <bits/stdc++.h>
using namespace std;

/*15. Prims Algorithm for Minimum Spanning tree

TC->
SC->
ASC->

*/

class cmp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        int mst[V];
        int key[V];
        int par[V];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < V; i++)
        {
            mst[i] = 0;
            key[i] = INT_MAX;
        }
        par[0] = -1;
        key[0] = 0;
        int minweight = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            int mini = pq.top().second;
            int u = pq.top().first;
            pq.pop();
            if (mst[u])
                continue;
            minweight += mini;
            mst[u] = 1;
            for (auto &it : adj[u])
            {
                int v = it[0], weight = it[1];
                if (mst[v] == 0 && weight < key[v])
                {
                    key[v] = weight;
                    par[v] = u;
                    pq.push({v, key[v]});
                }
            }
        }

        return minweight;
    }
};