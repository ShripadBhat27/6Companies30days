long long mod=1e9+7;
class Engineer{
    public:
    long long speed,efficiency;
    Engineer(long speed,long efficiency){
        this->speed=speed;
        this->efficiency=efficiency;
    }
    
};

bool cmp_Efficiency(Engineer A,Engineer B){
    return A.efficiency>B.efficiency;
}
struct cmp_speed{
    bool operator()(Engineer A,Engineer B){
        return A.speed>B.speed;
    }
};

class Solution {
public:
    long long maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        long long ans=0;
        vector<Engineer> v;
        for(int i=0;i<n;i++){
            v.push_back(Engineer(speed[i],efficiency[i]));
        }
        
        sort(v.begin(),v.end(),cmp_Efficiency);
        priority_queue<Engineer,vector<Engineer>,cmp_speed> q;
        long long speed_sum=0;
        for(int i=0;i<n;i++){
            if(q.size()==k){
                speed_sum=(speed_sum-q.top().speed);q.pop();
            }
            speed_sum=(speed_sum+v[i].speed);
            ans=max(ans,(speed_sum*v[i].efficiency));
            q.push(v[i]);
        }
        return ans%mod;
    }
};