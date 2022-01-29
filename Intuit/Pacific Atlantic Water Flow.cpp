class Solution {
public:
    int n,m;
    bool isIn(int i,int j){
        if(i<0||j<0||i==n||j==m) return false;
        return true;
    }
    
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>&visited,int PrevHeight){
        if(!isIn(i,j)||visited[i][j]||heights[i][j]<PrevHeight) return;
        
        visited[i][j]=true;
        dfs(i+1,j,heights,visited,heights[i][j]);
        dfs(i-1,j,heights,visited,heights[i][j]);
        dfs(i,j+1,heights,visited,heights[i][j]);
        dfs(i,j-1,heights,visited,heights[i][j]);
        
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false)),atlantic(n,vector<bool>(m,false));
        
        //1st and last row
        for(int j=0;j<m;j++){
            dfs(0,j,heights,pacific,heights[0][j]);
            dfs(n-1,j,heights,atlantic,heights[n-1][j]);
        }
        
        
        //1st col &last col
        for(int i=0;i<n;i++){
            
        dfs(i,0,heights,pacific,heights[i][0]);
        dfs(i,m-1,heights,atlantic,heights[i][m-1]);
        }
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]&&atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};