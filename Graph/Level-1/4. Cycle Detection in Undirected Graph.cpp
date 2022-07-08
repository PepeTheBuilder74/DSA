/* 4 . Detect cycle in undirected graph using DFS

1.Just do simple DFS and check if the adjacent node is != parent node then it means there is a cycle
2.TC->O(V+E)
3.SC->O(N)->visited array , O(V+E)->Adjancey list
4.ASC->O(N)->Recursion stack space

*/

const int N = 10e5;
int vis[N];

bool DFS(int vertex, vector<int> graph[], int parent)
{
    // mark source as visited
    vis[vertex] = 1;

    // go deeper and deeper into a node
    for (auto child : graph[vertex])
    {
        // if adjacent node  is visited then  dont do DFS
        if (!vis[child])
        {
            // if any of the call is true that means there is a cycle and we dont need to check further just return true
            if (DFS(child, graph, vertex))
            {
                return true;
            }
        }
        /*
        If adjacent is already visited it should only be parent , if it is other than  parent  iska mtlab ye hua dusra adjacent node bhi visited hai ,
        that implies there is a cycle eg: 1->2->3->1 : when we are at node 3 , it adjacent nodes are 2 and 1 but 2 is its parent that doesnt implies there is a
        cycle but 1 is also visited that means it is cyclic.
       */
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int vertices, m;
    cin >> vertices >> m;

    // creating adjancey list and taking input
    vector<int> graph[vertices + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int ans = 0;

    // loop because their might be different graphs in forest , so in order to visit all nodes we need loop for all vertices
    for (int i = 1; i <= vertices; i++)
    {
        // if node is already visited dont do DFS since all its connected components are already visited
        if (!vis[i])
        {
            ans = DFS(i, graph, -1);
        }
        // returns true means cycle exists
        if (ans)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

/*5. Detect Cycle in undirected graph using BFS

1. Do normal BFS and this time take queue of pair where we will store the adjacent node and its parent
2. TC->O(V+E)
3. SC->O(N)->queue,O(N)->visited,O(V+E)->adjancey list
4. ASC->O(1)

*/
const int n = 10e5;
vector<int> vis(n, 0);

bool bfs(int vertex, vector<int> graph[])
{
    // Mark source as visited
    vis[vertex] = 1;

    // pair to store node and its parent
    queue<pair<int, int>> q;

    // parent for src is -1
    q.push({vertex, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // visit all possible child of the src node
        for (auto child : graph[node])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push({child, node});
            }

            /*
            If adjacent is already visited it should only be parent , if it is other than  parent  iska mtlab ye hua dusra adjacent node bhi visited hai ,
            that implies there is a cycle eg: 1->2->3->1 : when we are at node 3 , it adjacent nodes are 2 and 1 but 2 is its parent that doesnt implies there is a
            cycle but 1 is also visited that means it is cyclic.
           */
            else if (child != parent)
            {
                // cycle exists
                return true;
            }
        }
    }
    // cylce doesnt exist
    return false;
}