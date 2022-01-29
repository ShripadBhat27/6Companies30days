// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int m,n;
    string word;
    bool isInBoard(int i,int j){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& visited,int word_index){
        
        if(word_index==word.length()-1) return true;
        visited[i][j]=true;
        bool possible[4]={false,false,false,false};
        if(isInBoard(i+1,j)&&board[i+1][j]==word[word_index+1]&&!visited[i+1][j])
            possible[0]=dfs(board,i+1,j,visited,word_index+1);
        if(isInBoard(i-1,j)&&board[i-1][j]==word[word_index+1]&&!visited[i-1][j])
            possible[1]=dfs(board,i-1,j,visited,word_index+1);
        if(isInBoard(i,j+1)&&board[i][j+1]==word[word_index+1]&&!visited[i][j+1])
            possible[2]=dfs(board,i,j+1,visited,word_index+1);
        if(isInBoard(i,j-1)&&board[i][j-1]==word[word_index+1]&&!visited[i][j-1])
            possible[3]=dfs(board,i,j-1,visited,word_index+1);
        
        visited[i][j]=false;
        
        return possible[0]|possible[1]|possible[2]|possible[3];
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        this->word=word;
        n=board.size();m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,visited,0))
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends