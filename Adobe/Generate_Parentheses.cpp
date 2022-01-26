// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    void solve(int n,int i,string s,int op,int cl){
        if(i==2*n){
            ans.push_back(s);return;
        }
        
        if(op<n)
        solve(n,i+1,s+"(",op+1,cl+1);
        
        if(cl>0)
        solve(n,i+1,s+")",op,cl-1);
        
        
        return;
        
    }
    vector<string> AllParenthesis(int n) {
    
        solve(n,0,"",0,0);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n); 
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends