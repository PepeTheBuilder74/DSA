/* 1. create graph*/

/* 1.a Adjency Matrix
SC->O(V^2) 
*/

// Adjency graph declaration
const int x = 10e3;
int graph[x + 1][x + 1];

int main()
{
    // n = nodes , m = edges
    int n, m;
    cin >> n >> m;

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;

        /* if weight is given then
           graph[u][v]=wt;
            */
    }
    return 0;
}

/*
->Advantages of Adjacency Matrix Representation :

    1.We can determine if two vertices are adjacent to each other in constant time.
    2.We can add an edge in the graph in constant time.
    3.We can delete an edge form the graph in constant time.

->Disadvantages of Adjacency Matrix Representation :

    1.The size of adjacency matrix is V^2. Suppose there is a graph with 1000 vertices and 1 edge. We are using an array of size 10002 for storing one edge which is a waste of memory.
    2.Traversing the graph using algorithms like DPS/BFS requires O(V^2)
    time in case of adjacency matrix whereas we can traverse the graph in O(V + E) time using adjacency list.

->When to use Adjacency Matrix ?

    1.If the graph contains edges in order of V^2,then it is better to use adjacency matrix as compared to adjacency list.
    This is because the size of both adjacency list and adjacency matrix will be comparable so using adjacecny matrix doesn’t necceessary
    waste a lot of memeory.
    2.If we want to perform operations like add / delete or check that the vertices are adjancent or not very frequently, then it is
    recommended to use adjacency matrix since we can perform these operations in constant time.

*/

/* 1.b Representation through list 
SC-> O(V+E) (vertices+edges)   
*/

int main()
{
    int vertices, m;
    cin >> vertices >> m;
    vector<pair<int, int>> graph[vertices + 1];
    for (int i = 0; i < vertices; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[v].push_back({u, wt});
        graph[u].push_back({v, wt});
    }
}

/*
Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in a graph thus consuming O(V^2) space.
Adding a vertex is easier. Computing all neighbors of a vertex takes optimal time.

Cons: Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done O(V).
*/

/*  visit : https://www.geeksforgeeks.org/comparison-between-adjacency-list-and-adjacency-matrix-representation-of-graph/  */
