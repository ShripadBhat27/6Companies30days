// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k){
        //dequeue  of indicies :try maintaining decreasing order
        deque<int> q;
        int left=0,right=0;
        vector<int> ans;
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends