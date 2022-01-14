// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> q;
        vector<int> ans;
        int left=0,right=0;
        
        while(left<=n-k){
            while(!q.empty()&&left>q.front()) q.pop_front();
            
            if(q.empty()){
                q.push_back(right);
            }
            else{
                while(!q.empty()&&arr[q.back()]<arr[right]) q.pop_back();
                q.push_back(right);
            }
            
            if(right-left+1==k){
                ans.push_back(arr[q.front()]);left++;
            }
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends