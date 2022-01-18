// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class graph{
    int n;
    list<int>* g;
    bool *visited,*isInstack;
    public:
    graph(){;}
    graph(int N,vector<pair<int, int> >& pre){
        n=N;
        visited=new bool[N+1];isInstack=new bool[N+1];
        g=new list<int>[N];
        for(int i=0;i<pre.size();i++){
            g[pre[i].second].push_back(pre[i].first);
        }
    }
    
    bool isCycle(){
        for(int i=0;i<n;i++){
            visited[i]=false;
            isInstack[i]=false;
        }
        for(int i=0;i<n;i++)
            if(!visited[i]&&dfs(i)==true) return true;
        return false;
    }
    
    bool dfs(int curr){
        visited[curr]=true;isInstack[curr]=true;
        
        for(auto nbr:g[curr]){
            if(isInstack[nbr]==true) return true;
            
            else if(!visited[nbr]){
                bool wasCycle=dfs(nbr);
                if(wasCycle==true) return true;
            }
        }
        
        isInstack[curr]=false;
        return false;
    }
    
};


class Solution{
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    graph gr(N,prerequisites);
	    
	    return !gr.isCycle();
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends