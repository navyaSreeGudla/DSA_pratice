class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        unordered_map<int,int>dist;
        for(const auto &time:times){
            adj[time[0]].push_back({time[2],time[1]});
        }
        for(int i = 1;i<=n;i++){
            dist[i]=INT_MAX;
        }
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){

            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(const auto&[d,v]:adj[node]){
                 if(d+dist[node]<dist[v]){
                    dist[v]=d+dist[node];
                    pq.push({dist[v], v});
                 }
            }
        }
        int res = 0;
        for (const auto& [node, time] : dist) {
            res = max(res, time);
        }
        return res == INT_MAX ? -1 : res;
    }
};
