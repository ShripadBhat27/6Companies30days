// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    string ans;
    //Function to find the largest number after k swaps.
    void helper(string&str,int i,int k){
        if(k==0)   return ;
        
        char maxd=str[i];
        for(int j=i+1;j<str.length();j++){
            if(str[j]>maxd){
                maxd=str[j];
            }
        }
        if(maxd!=str[i]) k--;
        for(int j=str.length()-1;j>=i;j--){
            if(str[j]==maxd){
                swap(str[i],str[j]);
                ans=max(ans,str);
                helper(str,i+1,k);
                swap(str[i],str[j]);
            }
        }
        
       
    }
       
        
    string findMaximumNum(string str, int k){
        ans=str;
        helper(str,0,k);
        return ans;
    }
 };

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends