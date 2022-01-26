// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  string nextPermutation(string nums) {
        int n=nums.size();
        int i,mini=n-1;
        for( i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                break;
            }
        }
        if(i==0) return nums;//descending 
        
        int j=n-1;
        if(i>0){
            while(nums[j]<=nums[i-1]&&j) j--;
            
            swap(nums[i-1],nums[j]);
        }
        reverse(nums.begin()+i,nums.end());
        return nums;
    }
    
    string nextPalin(string N) { 
        int n=N.length();
        string ans;
        string half=nextPermutation(N.substr(0,n/2));
        string second_half=half;
        reverse(second_half.begin(),second_half.end());
        if(n%2==0){
            ans= half+second_half;
        }
        else    
        ans=half+N[n/2]+second_half;
        
        if(ans==N) return "-1";
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends