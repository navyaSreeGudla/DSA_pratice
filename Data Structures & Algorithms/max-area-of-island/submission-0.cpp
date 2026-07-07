class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int res = 1;
        res = res+dfs(r+1,c,grid)+dfs(r,c+1,grid)+dfs(r-1,c,grid)+dfs(r,c-1,grid);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                  area = max(area,dfs(i,j,grid));
                }
            }
        }
        return area;
    }
};
