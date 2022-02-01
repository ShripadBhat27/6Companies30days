class graph{
    int n;
    map<int,list<pair<int,double> >> g;
    public:
    graph(int n){this->n=n;}
    void addedge(int x,int y,double wt){
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
    
    double djiktra(int start,int end){
        set<pair<double,int > > s;
        vector<double> prob(n,0);
        prob[start]=1;
        s.insert({prob[start],start});
        while(!s.empty()){
            auto curr=(s.rbegin());
            int node=(*curr).second;double wt=(*curr).first;
            s.erase(prev(s.end()));
            
            for(auto nbr:g[node]){
                if(nbr.second*wt>prob[nbr.first]){
                        
                        auto f=s.find({prob[nbr.first],nbr.first});
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        prob[nbr.first]=nbr.second*wt;
                        s.insert({prob[nbr.first],nbr.first});
                }
            }
        }
        
        return prob[end];
    }
    
};


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        graph g(n);
        for(int i=0;i<edges.size();i++)
            g.addedge(edges[i][0],edges[i][1],succProb[i]);
        
        
        return g.djiktra(start,end);
            
    }
};