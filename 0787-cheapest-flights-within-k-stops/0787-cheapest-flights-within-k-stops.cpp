class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        //stops,node,dist
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.second.first;
            int stops=it.first;
            int cost=it.second.second;
            if(stops>k)
                continue;
            for(auto &iter:adj[node])
            {
                int adjnodes=iter.first;
                int adjw=iter.second;
                
                if(cost+adjw<dist[adjnodes] && stops<=k)
                {
                    dist[adjnodes]=cost+adjw;
                    q.push({stops+1,{adjnodes,cost+adjw}});
                }
            }
        }
        
        return (dist[dst]!=1e9)?dist[dst]:-1;
    }
};