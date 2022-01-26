// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int no=0;
        bool is_negative=false;
        for(int i=0;i<str.length();i++){
            if(str[i]>='0'&&str[i]<='9'){
                no=no*10+(str[i]-'0');
            }
            else if(str[i]=='-') is_negative=true;
            else return -1;
        }
        
        if(is_negative)
        no*=-1;
        
        return no;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends