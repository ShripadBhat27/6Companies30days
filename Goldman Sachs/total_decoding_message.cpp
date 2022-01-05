// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    long long mod=1e9+7;
	    long long dp[10005];
	    long long solve(int i,string s){
	        if(s[i]=='0') return dp[i]=0;
	        if(i>=s.length()-1)
		        return dp[i]=1;
	        if(dp[i]!=-1) return dp[i];
	        long long ans=0;
	        ans=solve(i+1,s)%mod;

	        if(stoi(s.substr(i,2))<27)
		        ans=(ans+solve(i+2,s)%mod)%mod;

	        return dp[i]=ans;
        }

		long long  CountWays(string str){
		    // Code here
		    memset(dp,-1,sizeof(dp));

        	return solve(0,str);

		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends