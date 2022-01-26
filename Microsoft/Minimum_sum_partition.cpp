// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	long long minDifference(int arr[], int n)  { 
	    long long tot=0,ans=INT_MAX;
	    for(long long i=0;i<n;i++) tot+=arr[i];
	    
	    bool dp[n+1][tot+1];
	    for(int i=0;i<=n;i++)
	        dp[i][0]=true;
	    for(int i=1;i<=tot;i++)
	        dp[0][i]=false;
	        
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=tot;j++){
	                dp[i][j]=dp[i-1][j];
	                
	                if(arr[i-1]<=j)
	                    dp[i][j]|=dp[i-1][j-arr[i-1]];
	            }
	        }

	    
	    for(int j=tot/2;j>=0;j--){
	        if(dp[n][j]){
	            ans=tot-2*j;break;
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends