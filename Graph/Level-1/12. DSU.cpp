#include <bits/stdc++.h>
using namespace std;

/*16. DSU

TC->
SC->
ASC->

*/

const int N = 10e5;
int parent[N];
int Rank[N];

void make(int vertex)
{
    parent[vertex] = vertex;
}

int find(int vertex)
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
        if (Rank[parentOfFirstComponent] > Rank[parentOfSecondComponent])
        {
            parent[parentOfSecondComponent] = parent[parentOfFirstComponent];
        }
        else if (Rank[parentOfFirstComponent] < Rank[parentOfSecondComponent])
        {
            parent[parentOfFirstComponent] = parent[parentOfSecondComponent];
        }
        else
        {
            parent[parentOfFirstComponent] = parent[parentOfSecondComponent];
            Rank[parentOfSecondComponent]++;
        }
    }
}
