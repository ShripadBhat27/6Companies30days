// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


char to_lower(char c){
    return c+('a'-'A');
}
class Solution{
    public:
    string amendSentence (string s){
        string ans="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                if(i==0)
                    ans=ans+to_lower(s[i]);
                else
                    ans=ans+" "+to_lower(s[i]);
            }
            else 
            ans+=s[i];
        }
        
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends