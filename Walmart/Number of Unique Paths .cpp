// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int no_way(int i,int j,int a,int b){
        if(a==i&&b==j) return 1;
        
        int ans=0;
        if(i+1<=a) ans+=no_way(i+1,j,a,b);
        if(j+1<=b) ans+=no_way(i,j+1,a,b);
        return ans;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        
        return no_way(1,1,a,b);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends