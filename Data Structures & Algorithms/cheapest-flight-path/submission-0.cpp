class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }
         priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>, greater<>>pq;
        dist[src][0]=0;
        pq.push({0,src,-1});

        while(!pq.empty()){
            auto [cst, node, stops] = pq.top();
            pq.pop();
            if(node==dst){
                return cst;
            }
            if(stops==k){
                continue;
            }
            for(auto &[nei,w]:adj[node]){
                int nextCst = cst+w;
                int nextStops = stops+1;
                if(dist[nei][nextStops]>nextCst){
                    dist[nei][nextStops]=nextCst;
                    pq.push({nextCst,nei,nextStops});
                }
            }
        }
        return -1;
    }
};
