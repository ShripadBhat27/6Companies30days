// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

long long expo(int a,int n){
    long long ans=1;
    //O(logN)

    while(n>0){
        if(n&1)
            ans*=a;
        a*=a;
        n=n>>1;
    }
    return ans;
}
class Solution{
    public:
    long long int dp[1001][1001];
    long long int p=1e9+7;
    long long int solve(int n,int x,int i){
        if(n==0) return 1;
        if(i>n) return 0;
        if(dp[n][i]!=-1) return dp[n][i]%p;
        int res=0;
        long long int t=expo(i,x);
        if(t<=n){
            dp[n][i]=solve(n-t,x,i+1)+solve(n,x,i+1);
        }
        else{
            dp[n][i]=0;
        }
        return dp[n][i]%p;
    }
    long long int numOfWays(int n, int x){
        memset(dp,-1,sizeof(dp));
        
        return solve(n,x,1);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends