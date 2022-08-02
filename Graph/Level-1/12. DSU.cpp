#include <bits/stdc++.h>
using namespace std;

/*16. DSU

TC->
SC->
ASC->

*/

const int N = 10e5;
int parent[N];
int rank[N];

void make(int vertex)
{
    parent[vertex] = vertex;
}

void find(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    // path compression
    return parent[vertex] = find(parent[vertex]);
}

void union(int a, int b)
{
    int parentOfFirstComponent = find(a);
    int parentOfSecondComponent = find(b);

    if (parentOfFirstComponent != parentOfSecondComponent)
    {
        if (rank[parentOfFirstComponent] > rank[parentOfSecondComponent])
        {
            parent[parentOfSecondComponent] = parent[parentOfFirstComponent];
        }
        else if (rank[parentOfFirstComponent] < rank[parentOfSecondComponent])
        {
            parent[parentOfFirstComponent] = parent[parentOfSecondComponent];
        }
        else
        {
            parent[parentOfFirstComponent] = parent[parentOfSecondComponent];
            rank[parentOfSecondComponent]++;
        }
    }
}
