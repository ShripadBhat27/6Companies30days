#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    int c,d;
    bool ans;//tell if edge between c&d is bridge
    public:
    void dfs(int curr,int prt,vector<int> adj[],vector<bool>&vis,vector<int>&low,vector<int>&tin,int&timer){
      vis[curr]=true;tin[curr]=low[curr]=timer++;
      
      for(auto nbr:adj[curr]){
          if(nbr==prt) continue;
          if(!vis[nbr]){
              dfs(nbr,curr,adj,vis,low,tin,timer);
              low[curr]=min(low[curr],low[nbr]);
              if(low[nbr]>tin[curr]){
                  //bridge aahe
                  if((nbr==d&&curr==c)||(curr==d&&nbr==c)){
                      ans=true;
                  }
              }
              
          }else{
                  low[curr]=min(low[curr],low[nbr]);
              }
      }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) {
        this->c=c;this->d=d;ans=false;
        vector<int> time_visited(V,-1);
        vector<int> lowest_adjtime(V,-1);
        vector<bool> visited(V,false);
        int timer=0;
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,adj,visited,lowest_adjtime,time_visited,timer);
            }
        }
        
        
        return ans;
         
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends