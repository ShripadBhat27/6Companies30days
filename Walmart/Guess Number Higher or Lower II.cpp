class Solution {
public:
    int dp[201][201];
    
    int solve(int l,int r){
        if(l>=r) return 0;
        if(dp[l][r]!=0) return dp[l][r];
        int res=INT_MAX;
        for(int i=l;i<=r;i++){
            int tmp=i+max(solve(l,i-1),solve(i+1,r));
            res=min(res,tmp);
        }
        dp[l][r]=res;
        return res;
    }
    int getMoneyAmount(int n) {
        memset(dp,0,sizeof(dp));
        
        
        
        return solve(1,n); 
    }
};