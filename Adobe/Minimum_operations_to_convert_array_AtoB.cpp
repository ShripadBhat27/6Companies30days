#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  long long dp[1001][1001];
  long long solve(int a[],int b[],int n,int m){
      if(n==0) return m;
      if(m==0) return n;
      if(dp[n][m]!=-1) return dp[n][m];
      if(a[n-1]==b[m-1]) return dp[n][m]=solve(a,b,n-1,m-1);
      
      return dp[n][m]=min(solve(a,b,n-1,m),solve(a,b,n,m-1))+1;
  }
    long long minInsAndDel(int A[], int B[], int N, int M) {
        
        memset(dp,-1,sizeof(dp));
        return solve(A,B,N,M);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends