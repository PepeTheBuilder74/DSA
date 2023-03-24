#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,q; cin>>n>>q;
   vector<long long > a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<long long > pre(n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    while(q--){
        int l,r; cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}