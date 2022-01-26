// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[502][502];
    int solve(vector<int>&arr,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
        int righty=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
        
        return dp[i][j]= max(left,righty);
    }
    int maxCoins(vector<int>&A,int n)
    {
        memset(dp,-1,sizeof(dp));
	    return solve(A,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends