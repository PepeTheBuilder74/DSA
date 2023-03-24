#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int arr[N];
int ST[4*N];

void build(int node,int start,int end){
     if(start==end){  ST[node]=arr[start]; return; }
     int mid=(start+end)/2;
     int left=2*node,right=2*node+1;
     build(left,start,mid);
     build(right,mid+1,end);
     ST[node]=max(ST[left],ST[right]);
}
void queryUpd(int node,int start,int end,int val){
        if(ST[node]<val){
            cout<<0<<" ";
            return;
        }
        if(start==end){
            ST[node]-=val;
            cout<<start<<" ";
            return;
        }
        if(ST[2*node]>=val){
            queryUpd(2*node,start,(start+end)/2,val);
        }
        else{
            queryUpd(2*node+1,(start+end)/2+1,end,val);
        }
        ST[node]=max(ST[2*node],ST[2*node+1]);
}
int main() {
    int n,m;  cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(m--){
        int x; cin>>x;
        queryUpd(1,1,n,x);
    }
}