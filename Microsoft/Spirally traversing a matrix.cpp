// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int depth=min((c/2),(r/2));
        int i=0,j=0;
        vector<vector<bool> > seen(r,vector<bool>(c,false));
        for(int curr=0;curr<=depth;curr++){
            
            while(j<c-curr){
                if(!seen[i][j])
                {ans.push_back(matrix[i][j]);seen[i][j]=true;}
                j++;
            }j--;i++;
            while(i<r-curr){
                if(!seen[i][j])
                {ans.push_back(matrix[i][j]);seen[i][j]=true;}
                i++;
            }i--;j--;
            
            while(j>=curr){
                if(!seen[i][j])
                {ans.push_back(matrix[i][j]);seen[i][j]=true;}
                j--;
            }j++;i--;
            
            while(i>curr){
                if(!seen[i][j])
                {ans.push_back(matrix[i][j]);seen[i][j]=true;}
                i--;
            }i++;j++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends