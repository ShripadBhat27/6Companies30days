// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<char>> dial={{'#'},{'#'},{'a','b','c'},
        {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
    };
    vector<string>ans;
    
    void solve(int a[],int i,int n,string s){
        if(i==n){
            ans.push_back(s);return;
        }
        
        for(auto ch:dial[a[i]])
            solve(a,i+1,n,s+ch);
            
            
        return ;
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        solve(a,0,N,"");
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends