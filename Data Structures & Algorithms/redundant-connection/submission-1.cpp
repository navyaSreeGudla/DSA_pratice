class DSU{
public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        bool unite(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(pu == pv){
                return false;
            }
            if(size[pu]<size[pv]){
                swap(pu,pv);
            }
            parent[pv]=pu;
            size[pu]=size[pu]+size[pv];
            return true;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU Dsu(n);
        for(const auto& e:edges){
            if(!Dsu.unite(e[0],e[1])){
                return {e[0],e[1]};
            }
        }
        return {};
    }
};
