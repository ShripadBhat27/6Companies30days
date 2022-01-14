class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=0,n=arr.size();
        int maxi=0;
       
        while(i<=n-3){
            if(arr[i]<arr[i+1]) {
            int cnt=1;
            int j=i;
            bool isPossible=false;
            while(j+1<n&&arr[j]<arr[j+1]) {cnt++;j++;}
            while(i!=j&&j+1<n&&arr[j]>arr[j+1]) {cnt++;j++;isPossible=true;}
          
            if(isPossible){
            maxi=max(maxi,cnt);
            }
                
            }
            i++;
         }
        
        return maxi;
    }
};