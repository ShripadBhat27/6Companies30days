class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int> > q;
        int m=grid.size(),n=grid[0].size();
        int cnt1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1) cnt1++;
                else if(grid[i][j]==2) q.push({i,j});
        }
        while(cnt1&&!q.empty()){
            ans++;
            int curr=q.size();
            
            while(curr){
                int i=q.front().first,j=q.front().second;q.pop();curr--;
                
                if(i-1>=0&&grid[i-1][j]==1){
                    cnt1--;grid[i-1][j]=2;q.push({i-1,j});
                }
                if(i+1<m&&grid[i+1][j]==1){
                    cnt1--;grid[i+1][j]=2;q.push({i+1,j});
                }
                if(j-1>=0&&grid[i][j-1]==1){
                    cnt1--;grid[i][j-1]=2;q.push({i,j-1});
                }
                if(j+1<n&&grid[i][j+1]==1){
                    cnt1--;grid[i][j+1]=2;q.push({i,j+1});
                }
                
            }
        }
        
        
        return (cnt1>0)?-1:ans;
    }
};