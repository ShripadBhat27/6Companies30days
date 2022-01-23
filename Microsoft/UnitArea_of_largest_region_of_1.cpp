// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int m,n;
    int dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        if(i<0||j<0||i>=n||j>=m) return 0;
        visited[i][j]=true;
        if(grid[i][j]==0) return 0;
        
        visited[i][j]=true;
        int ans=1;
        // cout<<i<<" "<<j<<"\n";
        if(i+1<n&&!visited[i+1][j]&&grid[i+1][j]==1)
         ans+=dfs(i+1,j,visited,grid);
        if(i-1>=0&&!visited[i-1][j]&&grid[i-1][j]==1)
         ans+=dfs(i-1,j,visited,grid);
         
        if(j+1<m&&!visited[i][j+1]&&grid[i][j+1]==1)
         ans+=dfs(i,j+1,visited,grid);
         
        if(j-1>=0&&!visited[i][j-1]&&grid[i][j-1]==1)
         ans+=dfs(i,j-1,visited,grid);
        
        if(i+1<n&&j+1<m&&!visited[i+1][j+1]&&grid[i+1][j+1]==1)
         ans+=dfs(i+1,j+1,visited,grid);
        
        if(i+1<n&&j-1>=0&&!visited[i+1][j-1]&&grid[i+1][j-1]==1)
         ans+=dfs(i+1,j-1,visited,grid);
        
        if(i-1>=0&&j+1<m&&!visited[i-1][j+1]&&grid[i-1][j+1]==1)
         ans+=dfs(i-1,j+1,visited,grid);
         
        if(i-1>=0&&j-1>=0&&!visited[i-1][j-1]&&grid[i-1][j-1]==1)
         ans+=dfs(i-1,j-1,visited,grid);
        
        
        return ans;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        n=grid.size();m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    maxi=max(maxi,dfs(i,j,visited,grid));
                }
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends