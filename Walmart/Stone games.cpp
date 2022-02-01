class Solution {
public:
    int dp[501][501];
    int AliceScore(vector<int>&piles,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int lefty=piles[i]+min(AliceScore(piles,i+1,j-1),AliceScore(piles,i+2,j));
        int righty=piles[j]+min(AliceScore(piles,i,j-2),AliceScore(piles,i+1,j-1));
        return dp[i][j]=max(lefty,righty);
    }
    bool stoneGame(vector<int>& piles) {
        int tot=0;
        int n=piles.size();
   
        memset(dp,-1,sizeof(dp));
        for(auto x:piles) tot+=x;
        if(2*AliceScore(piles,0,n-1)>tot) return true;
        return false;
    }
};