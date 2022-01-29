class Solution {
public:
    int dist(vector<int>&p1,vector<int>&p2){
        int x=abs(p1[0]-p2[0]),y=abs(p1[1]-p2[1]);
        
        return x*x+y*y;
    }
    int nP2(int n){
        return (n*(n-1));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0,n=points.size();
        map<pair<int,int>,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    m[make_pair(i,dist(points[i],points[j]))]++;
                }
                
            }
        }
        
        for(auto x:m){
            ans+=nP2(x.second);
        }
        return ans;
    }
};