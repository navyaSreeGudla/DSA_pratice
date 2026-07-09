class Solution {
public:
    bool dfs(int node,int par,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(int curr:adj[node]){
            if(!vis[curr]){
                if(dfs(curr,node,adj,vis)){
                    return true;
                }
            }
            else if(curr!=par){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
         for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool>vis(n+1,false);
            if(dfs(u,-1,adj,vis)){
                return {u,v};
            }
         }
         return {};
    }
};
