#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
ll arr[N];
ll ST[4*N];

void build(int node,int start,int end){
     if(start==end){  ST[node]=arr[start]; return; }
     int mid=(start+end)/2;
     int left=2*node,right=2*node+1;
     build(left,start,mid);
     build(right,mid+1,end);
     
     // Only Change for Build in Normal ST
     ST[node]=min(ST[node*2],ST[node*2+1]);
}
ll query(int node,int start,int end,int l,int r){
     
     // Change Return accn to question
     if(end<l || start>r)return INT_MAX;
     if(start==end){  return ST[node];}
     if(start>=l && end<=r)return ST[node];
     int mid=(start+end)/2;
     ll leftAns= query(node*2,start,mid,l,r);
     ll rightAns= query(node*2+1,mid+1,end,l,r);
     
     // depends on question
     return min(leftAns,rightAns);
}

void update(int node,int start,int end,int val,int pos){
        if(start==end){
            ST[node]=val;
            arr[pos]=val;
            return;
        }
        int mid=(start+end)/2;
        if(pos>=start && pos<=mid){
            update(node*2,start,mid,val,pos);
           
        }
        else {
           update(node*2+1,mid+1,end,val,pos);
        }
        ST[node]=min(ST[node*2],ST[node*2+1]);
}


int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int idx,val; cin>>idx>>val;
            update(1,1,n,val,idx);
        }
        else {
           int l,r;cin>>l>>r;
           cout<< query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}
