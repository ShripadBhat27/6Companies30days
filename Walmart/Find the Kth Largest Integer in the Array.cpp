struct cmp{
  bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};


class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,cmp> q;
        
        for(auto x:nums){
            q.push(x);
            if(q.size()>k)
                q.pop();
        }
        
        
        return q.top();
    }
};