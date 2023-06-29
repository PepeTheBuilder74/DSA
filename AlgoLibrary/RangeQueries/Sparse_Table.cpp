#include <bits/stdc++.h>
using namespace std;
template<class T>
class sparseTable
{
    public:
    int n,k;
    vector<vector<T>> table;
    vector<T> logs;
    function<T(T,T)> operation;
    void init(int x,function<T(T,T)> _operation)
    {  
            operation=_operation;
            n=x;
            logs.resize(n+1);
            logs[1]=0;
            for(int i=2;i<=n;i++)
                    logs[i]=logs[i/2]+1;
            k=*max_element(logs.begin(),logs.end());
            table.resize(k+1,vector<T>(n));
    }

    void build(vector<T> &arr)
    {
        for(int i=0;i<n;i++)
                table[0][i]=arr[i];
 
        for(int j=1;j<=k;j++)
        {
            for(int i=0;i+(1<<j)<=n;i++)
                table[j][i]=operation(table[j-1][i],table[j-1][i+(1<<(j-1))]);
        }
    }
    // 1 based indexing
    T query(int l , int r)
    {
        assert(l<=r);
        assert(l>=0 && r<n);
        int j = logs[r - l + 1];
        T answer = operation(table[j][l], table[j][r-(1<<j)+1]);
        return answer;
    }
};

int main(){
  int n;cin>>n;
  vector<long long int> arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  sparseTable<long long int > st;
  auto operation=[](long long a,long long b){
    return min(a,b);
  };
  st.init(n,operation);
  st.build(arr);
  int q;cin>>q;
  while(q--){
    int l,r;cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}