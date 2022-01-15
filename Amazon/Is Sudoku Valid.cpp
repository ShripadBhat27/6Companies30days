// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool notInRow(vector<vector<int>> &arr, int row){
        // Set to store characters seen so far.
        set<int> st;
 
        for (int i = 0; i < 9; i++) {
 
        // If already encountered before, return false
            if (st.find(arr[row][i]) != st.end())
                return false;
 
        // If it is not an empty cell, insert value
        // at the current cell in the set
            if (arr[row][i] != 0)
                st.insert(arr[row][i]);
        }
        return true;
    }

    bool notInCol(vector<vector<int>> &arr, int col){
    set<int> st;
 
    for (int i = 0; i < 9; i++) {
 
        // If already encountered before, return false
        if (st.find(arr[i][col]) != st.end())
            return false;
 
        // If it is not an empty cell,
        // insert value at the current cell in the set
        if (arr[i][col] != 0)
            st.insert(arr[i][col]);
    }
    return true;
}
 

bool notInBox(vector<vector<int>> &arr, int startRow, int startCol)
{
    set<int> st;
 
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int curr = arr[row + startRow][col + startCol];
 
            // If already encountered before, return false
            if (st.find(curr) != st.end())
                return false;
 
            // If it is not an empty cell,
            // insert value at current cell in set
            if (curr != 0)
                st.insert(curr);
        }
    }
    return true;
}

    bool checkfor(vector<vector<int>> &arr,int row,int col){
        
        return notInRow(arr, row) && notInCol(arr, col) &&
           notInBox(arr, row - row % 3, col - col % 3);
    }

    int isValid(vector<vector<int>> arr){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                if(!checkfor(arr,i,j)) return 0;
        }
        
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends