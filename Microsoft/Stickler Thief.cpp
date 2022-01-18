// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    
    
    int FindMaxSum(int arr[], int n){
        if(n<2) return arr[0];
        else if(n==2) return max(arr[0],arr[1]);
        int dp [n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=arr[0];dp[1]=max(dp[0],arr[1]);
        
        int maxi=max(dp[0],dp[1]);
        
        for(int i=2;i<n;i++)
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        
        
        return max(dp[n-1],dp[n-2]);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends