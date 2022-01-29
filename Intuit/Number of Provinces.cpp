class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected,int i,vector<bool>&visited){
        visited[i]=true;
        for(int j=0;j<n;j++)
            if(!visited[j]&&isConnected[i][j]==1)
                dfs(isConnected,j,visited);
        
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;dfs(isConnected,i,visited);
            }
        }
        
        return ans;
    }
};