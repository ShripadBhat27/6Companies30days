class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> tz(n);//trailing zero in each row
        for(int i=0;i<n;i++){
            int j=n-1;
            while(j>=0&&grid[i][j]==0) j--;
            tz[i]=n-1-j;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int j;
            if(tz[i]>=n-1-i) continue;
            for( j=i+1;j<n;j++)
                if(tz[j]>=n-i-1) break;
            if(j==n) return -1;
            ans+=(j-i);
            int ele=tz[j];
            tz.erase(tz.begin()+j);
            tz.insert(tz.begin(),ele);
        }
        
        return ans;
    }
};
