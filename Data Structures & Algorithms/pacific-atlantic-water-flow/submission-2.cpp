class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& ocean){
        int n = heights.size();
        int m = heights[0].size();
        ocean[r][c]=true;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i =0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,heights,ocean);
            }
        }    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        vector<vector<int>>ans;
        for(int c =0;c<m;c++){
            dfs(0,c,heights,pac);
            dfs(n-1,c,heights,atl);
        }
        for(int r =0;r<n;r++){
            dfs(r,0,heights,pac);
            dfs(r,m-1,heights,atl);
        }
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
