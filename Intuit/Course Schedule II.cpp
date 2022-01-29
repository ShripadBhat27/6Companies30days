class Solution {
public:
    vector<vector<int> > g;
    vector<int> order;
    
   
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
             
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
            for(auto y:g[i])
                indegree[y]++;
            
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        
        while(!q.empty()){
            int node=q.front();q.pop();
            
            order.push_back(node);
            
            for(auto y:g[node]){
                indegree[y]--;
                if(indegree[y]==0)
                    q.push(y);
            }
        }
        
        
        if(order.size()!=numCourses)
            order.clear();
        
        
        return order;
        
    }
};