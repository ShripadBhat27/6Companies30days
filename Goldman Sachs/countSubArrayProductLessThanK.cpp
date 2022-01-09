// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    long long  countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long product=1;//product in given windown
        long long left=0,right=0,ans=0;
        
        while(right<n){
            product*=a[right];
            
            while(product>=k){
                product/=a[left];
                left++;
            }
            
            ans+=(right-left+1);
            right++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends