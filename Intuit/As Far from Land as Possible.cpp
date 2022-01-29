class Solution {
public:
    int n;
    bool isIn(int i,int j){
        if(i<0||j<0||i==n||j==n) return false;
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int> > cost(n,vector<int>(n,INT_MAX));
        
        queue<pair<int,int > > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    q.push({i,j});cost[i][j]=0;
                }
        }
        if(q.size()==0||q.size()==n*n) return -1;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(isIn(p.first+1,p.second)&&cost[p.first+1][p.second]>cost[p.first][p.second]+1){
                cost[p.first+1][p.second]=cost[p.first][p.second]+1;
                q.push({p.first+1,p.second});
            }
            if(isIn(p.first-1,p.second)&&cost[p.first-1][p.second]>cost[p.first][p.second]+1){
                cost[p.first-1][p.second]=cost[p.first][p.second]+1;
                q.push({p.first-1,p.second});
            }
            if(isIn(p.first,p.second+1)&&cost[p.first][p.second+1]>cost[p.first][p.second]+1){
                cost[p.first][p.second+1]=cost[p.first][p.second]+1;
                q.push({p.first,p.second+1});
            }
            if(isIn(p.first,p.second-1)&&cost[p.first][p.second-1]>cost[p.first][p.second]+1){
                cost[p.first][p.second-1]=cost[p.first][p.second]+1;
                q.push({p.first,p.second-1});
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ans=max(ans,cost[i][j]);
        }
        
        return ans;
    
    }
};