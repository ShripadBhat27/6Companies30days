class Solution {
public:
    bool isPossible(vector<int>&nums,int largest_sum,int m){
        int tot=0,subarray=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest_sum) return false;
            if(tot+nums[i]<=largest_sum){
                tot+=nums[i];
            }else{
                tot=nums[i];
                subarray++;
            }
        }
        return (subarray<=m);
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=1e9+7,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(isPossible(nums,mid,m))
                r=mid-1;
            else
                l=mid+1;
        }
        
        return l;
    }
};