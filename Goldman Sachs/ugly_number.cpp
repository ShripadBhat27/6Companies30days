// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	//ugly number x=(2^a)*(3^b)*(5^c)
	//so dp[i]=min(p1*2,p2*3,p3*5); where p1,p2,p3 are old ugly number
	ull getNthUglyNo(int n) {
	    //c2 gives index of number which was last multiplied by 2
	    
	    int c2=0,c3=0,c5=0;
	    
	    vector<ull> dp(n+1);
	    dp[0]=1;
	    for(ull i=1;i<n;i++){
	        dp[i]=min({2*dp[c2],3*dp[c3],5*dp[c5]});
	        if(dp[i]==2*dp[c2])
	            c2++;
	       if(dp[i]==3*dp[c3])
	            c3++;
	       if(dp[i]==5*dp[c5])
	            c5++;
	    }
	    
	    return dp[n-1];
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends