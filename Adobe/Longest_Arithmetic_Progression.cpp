// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2) return n;
        int ans=2;
        int dp[n][n];//dp[i][j] :no of AP with first two elements a[i] a[j]
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++)
            dp[i][n-1]=2; //as last element will be in AP of len 2 with any element
        
        //selecting middle element a[j]
        for(int j=n-2;j>=1;j--){
            int i=j-1,k=j+1;
            //find first a[i] & a[k] which are in AP with middle element a[j]
            //we know that a1+a3=2*a2
            while(i>=0&&k<=n-1){
                if(A[i]+A[k]==2*A[j]){ //in AP
                    dp[i][j]=dp[j][k]+1;
                    ans=max(ans,dp[i][j]);
                    i--;k++;//check for next possible triplet
                }
                else if(A[i]+A[k]<2*A[j])
                    k++; //as sorted so only increasing k can increase sum
                else
                  { dp[i][j]=2; i--;}//decreasing sum 
            }
            
            while(i>=0){ //if k reaches end ,then no triplet with i&j can be formed
                dp[i][j]=2;i--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends