// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

long long int fastModExp(long long int a,long long int b,long long int m){
    long long int res=1;
    while(b>0){
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }

    return res;

}


class Solution
{
  public:
    long long int kvowelwords(int N, int K) {
        long long int i,j;
        long long int mod=1e9+7;
        long long int dp[N+1][K+1];
        long long int sum=1;
        
        for(int i=1;i<=N;i++){
            dp[i][0]=sum*21;
            dp[i][0]%=mod;
            sum=dp[i][0];
            
            for(int j=1;j<=K;j++){
                if(j>i) dp[i][j]=0;
                else if(i==j)
                    dp[i][j]=fastModExp(5,i,mod);
                else
                    dp[i][j]=dp[i-1][j-1]*5;
                dp[i][j]%=mod;
                sum+=dp[i][j];
                sum%=mod;
            }
        }
        
        return sum;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends