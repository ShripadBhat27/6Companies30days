// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class graph{
    map<char,list<char>> gr;
    public:
    graph(){;}
    void addedge(char s,char d){
        gr[s].push_back(d);
    }
    void dfs_helper(char node,map<char,bool>&visited,string&ordering){
        visited[node]=true;
        for(auto nbr:gr[node]){
            if(!visited[nbr]) dfs_helper(nbr,visited,ordering);
        }
        
        ordering=node+ordering;
    }
    string dfs(){
        string ordering="";
        map<char,bool> visited;
        for(auto p:gr){
            visited[p.first]=false;
        }
        
        for(auto p:gr){
            if(!visited[p.first])
                dfs_helper(p.first,visited,ordering);
        }
        
        return ordering;
    }
};
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        graph g;
        for(int i=0;i<N-1;i++){
            int j=0,k=0;
            while(j<dict[i].length()&&k<dict[i+1].length()&&dict[i][j]==dict[i+1][k]){
                j++;k++;
            }
            g.addedge(dict[i][j],dict[i+1][k]);
        }
        return g.dfs();
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends