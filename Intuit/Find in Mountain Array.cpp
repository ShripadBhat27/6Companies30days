/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(int low,int high,MountainArray &mountainArr){
        int mid=(low+high)/2;
        
        if(mountainArr.get(mid)>mountainArr.get(mid-1)&&mountainArr.get(mid)>mountainArr.get(mid+1)) 
            return mid;
        else if(mountainArr.get(mid)>mountainArr.get(mid-1)&&mountainArr.get(mid+1)>mountainArr.get(mid))
            return findpeak(mid+1,high,mountainArr);
        else
            return findpeak(low,mid-1,mountainArr);
        
        return -1;
    }
    int searchAsc(int l,int r,int target,MountainArray &mountainArr){
        while(l<=r){
            int mid=(l+r)/2;
            int element=mountainArr.get(mid);
            if(element==target) return mid;
            else if(element <target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    int searchDesc(int l,int r,int target,MountainArray &mountainArr){
        while(l<=r){
            int mid=(l+r)/2;
            int element=mountainArr.get(mid);
            if(element==target) return mid;
            else if(element >target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak=findpeak(1,mountainArr.length()-1,mountainArr);
        int res=searchAsc(0,peak,target,mountainArr);
        if(res!=-1) return res;
        
        // cout<<peak<<" "<<res<<"\n";
        return searchDesc(peak,mountainArr.length()-1,target,mountainArr);
    }
};