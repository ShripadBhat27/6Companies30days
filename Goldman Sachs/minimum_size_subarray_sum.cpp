class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1);
        
        prefix[0]=0;
        prefix[1]=nums[0];
        
        for(int i=1;i<n;i++)
            prefix[i+1]=prefix[i]+nums[i];
        
        int mini=INT_MAX;
        
        for(int i=1;i<=n;i++){
            
            int to_find=target+prefix[i-1];
            int j=(lower_bound(prefix.begin(),prefix.end(),to_find)-prefix.begin());
            if(j<=n){
                mini=min(mini,j-i+1);
            }
        }
        
        
        return (mini!=INT_MAX)?mini:0;
    }
};