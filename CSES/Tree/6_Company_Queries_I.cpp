#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const ll INF = 1e18;

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
vector<int> adj[N];
const int LOG=20;
int up[N][LOG];
int Jump(int node,int jump){
    for(int i=LOG-1;i>=0;i--){
        if(jump&(1<<i)){
            node=up[node][i];
        }
    }
    return node?node:-1; 
}

void buildBinaryLifting(){
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}

void __solve_testcase(int test_case) {
     int n,q; cin>>n>>q;
     for(int i=2;i<=n;i++){
         int x; re(x);
         adj[x].pb(i); adj[i].pb(x);
         up[i][0]=x;
     }
     buildBinaryLifting();
     while(q--){
       int node,jump; cin>>node>>jump;
       cout<<Jump(node,jump)<<'\n';
     }
}
