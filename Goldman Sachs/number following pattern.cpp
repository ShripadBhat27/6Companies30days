// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:

    //so catch is :as we have minimum digit we try keeing as low as possible 
    //for lower indices of S
    
    //two important value to track 
    //1.Max value so far 2.last printed value
    
    string printMinNumberForPattern(string seq){
        int n = seq.length();
 
        if (n >= 9)
            return "-1";
 
        string result(n+1, ' ');
 
        int count = 1; 
 
        for (int i = 0; i <= n; i++){
            if (i == n || seq[i] == 'I'){
                for (int j = i - 1 ; j >= -1 ; j--){
                    result[j + 1] = '0' + count++;
                    if(j >= 0 && seq[j] == 'I')
                        break;
                }
            }
        }
    return result;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends