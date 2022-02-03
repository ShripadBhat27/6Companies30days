class Solution {
public:
    bool checkforzero(vector<int>&v){
        for(auto x:v) if(x==0) return true;
        return false;
    }
    vector<int> dfs(vector<int>&sums){
        if(!checkforzero(sums)) return vector<int>();
        
        int n=sums.size();
        if(n==2){
            if(sums[0]!=0) return vector<int>({sums[0]});
            return vector<int>({sums[1]});
        }
        int x=sums[n-1]-sums[n-2];
        map<int,int>cnt;
        for(auto x:sums) cnt[x]++;
        //check for +ve
        vector<int> newsum1;
        map<int,int>cnt1=cnt;
        for(int i=n-1;i>=0;i--){
            int a=sums[i],b=sums[i]-x;
            if(cnt1[a])
                if(cnt1[b]){
                    newsum1.push_back(b);cnt1[a]--;cnt1[b]--;
                }else
                    break;
        }
        vector<int>ans1;
        if(newsum1.size()*2==n){
            reverse(newsum1.begin(),newsum1.end());
            
            ans1=dfs(newsum1);ans1.push_back(x);
        }
        
        //check for -ve
        vector<int> newsum2;
      
        for(int i=0;i<n;i++){
            int a=sums[i],b=sums[i]+x;
            if(cnt[a])
                if(cnt[b]){
                    newsum2.push_back(b);cnt[a]--;cnt[b]--;
                }else
                    break;
        }
        vector<int>ans2;
        if(newsum2.size()==floor(n/2)){
            reverse(newsum2.begin(),newsum2.end());
            ans2=dfs(newsum2);ans2.push_back(-x);
        }
        
        return (ans1.size()>ans2.size())?ans1:ans2;
    }
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(),sums.end());
        return dfs(sums);
    }
};