class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(parent[node]!=node){
            parent[node]=find(parent[node]);
        }
        return parent[node];
    }
    bool unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
         if (pu == pv)
        return false;
        if(size[pu]<size[pv]){
            swap(pu,pv);
        }
        size[pu]=size[pu]+size[pv];
        parent[pv]=pu;
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<pair<int,pair<int,int>>>edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist,{i, j}});
            }
        }
        sort(edges.begin(),edges.end());
        int res = 0;
        for(auto &it:edges){
            int dist = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dsu.unite(u,v)){
                res = res+dist;
            }
        }
        return res;
    }
};
