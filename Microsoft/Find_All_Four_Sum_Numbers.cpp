// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n=arr.size();
        vector<vector<int> > ans;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
              
                
                int left=j+1,right=n-1;
                while(left<right){
                    if(arr[left]+arr[right]+arr[i]+arr[j]==k){
                        vector<int> append({arr[i],arr[j],arr[left],arr[right]});
                        ans.push_back(append);
                        left++;right--;
                    }
                    else if(arr[left]+arr[right]+arr[i]+arr[j]<k)
                    left++;
                    else
                    right--;
                    
                }
                
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends