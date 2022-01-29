class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int capacity){
        int d=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>capacity){
                sum=weights[i];d++;
            }
            else
                sum+=weights[i];
        }
        return (d<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=0,l=0,r=0;
        for(auto x:weights) {
            r+=x;
            l=max(l,x);
        }
        
        while(l<=r){
            
            int mid=(l+r)/2;
            if(isPossible(weights,days,mid)){
                r=mid-1;ans=mid;
            }else
                l=mid+1;
        }
        
        
        
        
        
        return ans;
    }
};