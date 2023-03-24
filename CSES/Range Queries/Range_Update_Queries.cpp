#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
ll arr[N];
ll lazy[4*N];

void build(int node,int start,int end){
     if(start==end){  lazy[node]=arr[start]; return; }
     int mid=(start+end)/2;
     build(2*node,start,mid);
     build(2*node+1,mid+1,end);
     lazy[node]=0;
}
void propagate(int node,int start,int end){
        if(start==end){ return; }
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
}
ll query(int node,int start,int end,int l,int r){
        propagate(node,start,end);
        if(end<l || start>r)return 0;
        if(start==end){  return lazy[node];}
        if(start>=l && end<=r)return lazy[node];
        int mid=(start+end)/2;
        ll ls= query(node*2,start,mid,l,r);
        ll rs= query(node*2+1,mid+1,end,l,r);
        return ls+rs;
}


void update(int node,int start,int end,int l,int r,int val){
      if(end<l || start>r)return;
      if(start==end){
          lazy[node]+=val;
          return;
      }
      else if(start>=l && end<=r){
          lazy[node]+=val;
          return;
      }
      else{
            int mid=(start+end)/2;
            update(node*2,start,mid,l,r,val);
            update(node*2+1,mid+1,end,l,r,val);
      }
}


int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int l,r,val; cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else {
           int l,r;cin>>l;
           cout<< query(1,1,n,l,l)<<'\n';
        }
    }
    return 0;
}