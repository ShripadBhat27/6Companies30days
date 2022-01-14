// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    vector<int>m(26,0);
		    string ans="";
		    queue<int> q;
		    for(auto ch:A){
		        m[ch-'a']++;
		        if(q.empty()){
		            if(m[ch-'a']==1){
		                ans+=ch;q.push(ch);
		            }
		            else
		                ans+='#';
		            
		        }
		        else{
		            
		            while(!q.empty()&&m[q.front()-'a']>1) q.pop();
		            
		            if(!q.empty())
		            ans+=q.front();
		            else
		                ans+='#';
		            if(m[ch-'a']==1) q.push(ch);
		        }
		       
		        
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends