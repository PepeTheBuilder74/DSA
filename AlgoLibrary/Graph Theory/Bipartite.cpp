template<typename T>
class check_bipartite{
    private:
       int V;
       vector<vector<int>>graph;
       vector<int>color;
       vector<array<vector<int>,2>>components;
    
    function<bool(int,int)>dfs=[&](int node,int col){
        color[node]=col;
        components.back()[col].emplace_back(node);
        for(auto &i:graph[node]){
            if(color[i]==-1){
                if(!dfs(i,col^1)){
                    return false;
                }
            }
            else if(color[i]==col){
                return false;
            }
        }
        return true;
    };
    public:
      check_bipartite(int V,vector<vector<int>>&graph){
            this->V=V;
            this->graph=graph;
            color.resize(V,-1);
      }
      bool is_bipartite(){
          for(int i=0;i<V;i++){
              if(color[i]==-1){
                  components.emplace_back(array<vector<int>,2>());
                  if(!dfs(i,0)){
                      return false;
                  }
              }
          }
          return true;
      }
      vector<array<vector<int>,2>>get_components(){
          return components;
      }
      vector<int>get_color(){
          return color;
      }
};