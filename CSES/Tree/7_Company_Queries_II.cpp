#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void __solve_testcase(int test_case);
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre_process();
 
    int no_of_testcase = 1;
    // cin >> no_of_testcase;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        // cout << "Case #" << testcase << ": ";
        __solve_testcase(testcase);
    }
    return 0;
}

// Two ways to solve this problem 
// 1. Using ET and Binary Lifting
// 2. Using normal LCA and Binary Lifting
vector<int> adj[N];
const int LOG=20;
int up[N][LOG];
int tin[N],tout[N],timer=1;
void dfs(int node,int p){
    tin[node]=timer++;
    for(auto child:adj[node]){
        if(child!=p){
            dfs(child,node);
        }
    }
    tout[node]=timer++;
}

bool is_ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u,int v){
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i=LOG-1;i>=0;--i){
        if(!is_ancestor(up[u][i],v)){
            u=up[u][i];
        }
    }
    return up[u][0];
}
void buildLcaTable(int n ){
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}

void __solve_testcase(int test_case) {
     int n,q; cin>>n>>q;
     for(int i=2;i<=n;i++){
         int x; cin>>x;
         adj[x].push_back(i); adj[i].push_back(x);
         up[i][0]=x;
     }
     // either pass 1 as parent or update up[1][0] to 1 later
     dfs(1,0);
     up[1][0]=1;
     buildLcaTable(n);
     while(q--){
        int u,v; cin>>u>>v;
        cout<<lca(u,v)<<'\n';
     }
}

// 2. Using normal LCA and Binary Lifting
vector<int> adj[N];
const int LOG=20;
int up[N][LOG];
int depth[N];
void dfs(int node,int p){
    depth[node]=depth[p]+1;
    up[node][0]=p;
    for(auto child:adj[node]){
        if(child!=p){
            dfs(child,node);
        }
    }
}

void buildLcaTable(int n){
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    // jump to same level
    int diff=depth[u]-depth[v];

    // jump to same level
    for(int i=0;i<LOG;++i){
        if(diff&(1<<i)){
            u=up[u][i];
        }
    }
    if(u==v) return u;
    
    // jump to lca
    for(int i=LOG-1;i>=0;--i){

        // if u and v don't have same ancestor then jump both of them by 2^i
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        adj[x].push_back(i); adj[i].push_back(x);
    }
    depth[0]=0;
    dfs(1,0);
    up[1][0]=1;
    buildLcaTable(n);
    while(q--){
        int u,v; cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
}
