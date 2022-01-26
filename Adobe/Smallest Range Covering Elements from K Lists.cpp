class element{
 
    public:
      int value,index,row,arrsize;
        //index :- position of element in array i.e j
        //row   :- array number i.e i
      element(int val,int indexnumber,int rownumber,int arraysize){
         value=val;
         index=indexnumber;
         row=rownumber;
         arrsize=arraysize; 
      }
 
};
struct compare{
       bool operator()(element a,element b){
         return a.value>b.value;
       }
 
   };


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        int low,high,mini,maxi,range;
        mini=INT_MAX;//tells current minimum in heap
        maxi=INT_MIN;//tells current maximum in heap
        range=INT_MAX;
        priority_queue<element,vector<element>,compare>pq;
        
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i][0]);maxi=max(maxi,nums[i][0]);
            pq.push(element(nums[i][0],0,i,nums[i].size()));
        }
        
        while(!pq.empty()){
            mini=pq.top().value;
            if(maxi-mini<range){
                range=maxi-mini;low=mini;high=maxi;
            }
            element e=pq.top();pq.pop();
            if(e.index+1==e.arrsize) break;
            maxi=max(maxi,nums[e.row][e.index+1]);
            pq.push(element(nums[e.row][e.index+1],e.index+1,e.row,e.arrsize));
        }
        
        
        ans[0]=low;ans[1]=high;
        return ans;
    }
};