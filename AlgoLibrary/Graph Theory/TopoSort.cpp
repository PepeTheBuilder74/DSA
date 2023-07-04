#include<bits/stdc++.h>
using namespace std;
template<typename T>
// 0 based Nodes
vector<T> topo_sort(const vector<vector<T>> &graph){
     int n=(int)graph.size();
     vector<T>in_degree(n,0);
     for(int i=0;i<n;i++){
          for(auto &child:graph[i]){
                in_degree[child]++;
          }
     }
     queue<T> bfs;
     for(int i=0;i<n;i++){
          if(in_degree[i]==0){
               bfs.push(i);
	  }
     }
     vector<T>ans;
     while(!bfs.empty()){
          T node=bfs.front();
          bfs.pop();
          ans.push_back(node);
          for(auto &i:graph[node]){
               in_degree[i]--;
               if(in_degree[i]==0){
                    bfs.push(i);
               }
          }
     }
     if((int)ans.size()!=n){
          return {};
     }
     return ans;
}
