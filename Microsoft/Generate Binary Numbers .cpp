// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

string toBinary(int n){
    string ans="";
    while(n){
        if(n%2==0)
            ans="0"+ans;
        else
            ans="1"+ans;
        n/=2;
    }
    
    return ans;
}
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1;i<=N;i++){
	    ans.push_back(toBinary(i));
	}
	
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends