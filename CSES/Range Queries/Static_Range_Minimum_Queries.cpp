#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int arr[N];
int ST[4*N];

void build(int node,int start,int end){
       if(start==end){
          ST[node]=arr[start];
          return;
       }
       int mid=(start+end)/2;
       build(2*node,start,mid);
       build(2*node+1,mid+1,end);
       ST[node]=min(ST[2*node],ST[2*node+1]);
}
int query(int node,int start,int end,int l,int r){
    if(end<l || start>r)return INT_MAX;
    if(start==end)return ST[node];
    if(start>=l && end<=r)return ST[node];
    int mid=(start+end)/2;
    int ls=query(2*node,start,mid,l,r);
    int rs=query(2*node+1,mid+1,end,l,r);
    return min(ls,rs);
}


int main(){
   int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int l,r; cin>>l>>r;
        cout<< query(1,1,n,l,r)<<'\n';
    }
    return 0;
}