#include <bits/stdc++.h>
using namespace std;

void __solve_testcase(int test_case);
void pre_process();
 
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
const int N = 2e5 + 5;
vector<int> adj[N];
const int LOG=20;
int par[N][LOG];
int tin[N],tout[N],timer=1;
int depth[N];
void dfs(int node,int p){
    tin[node]=timer++;
    par[node][0]=p;
    depth[node]=depth[p]+1;
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
        if(!is_ancestor(par[u][i],v)){
            u=par[u][i];
        }
    }
    return par[u][0];
}

int dist(int u,int v){
    // or you can use BIT and add in[u],1 and add out[v],-1 and then query for lca
   return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void __solve_testcase(int test_case) {
     int n,q; cin>>n>>q;
     for(int i=2;i<=n;i++){
         int u,v; cin>>u>>v;adj[u].pb(v); adj[v].pb(u);
     }
     dfs(1,0);
     par[1][0]=1;
     for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            par[j][i]=par[par[j][i-1]][i-1];
        }
     }
    while(q--){
        int u,v; re(u,v);
        cout<<dist(u,v)<<endl;
    }
}