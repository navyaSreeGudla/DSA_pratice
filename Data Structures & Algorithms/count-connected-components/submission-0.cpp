class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj ,vector<bool>& vis){
        if(vis[node]==true){
            return;
        }
        vis[node]=true;
        for(int neigh:adj[node]){
            dfs(neigh,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>adj(n);
     for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
     }
    vector<bool>vis(n,false);
    int cnt =0;
    for(int i =0;i<n;i++){
        if(vis[i]==false){
            dfs(i,adj,vis);
            cnt++;
        }
    }
    return cnt;
    }
};
