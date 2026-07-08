class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                     q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int d = q.front().first;
            q.pop();
            int dr[4]= {-1,0,1,0};
            int dc[4]= {0,-1,0,1};
            for(int i = 0;i<4;i++){
               int nr = row +dr[i];
               int nc = col +dc[i];
               if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==INT_MAX){
                grid[nr][nc]=d+1;
                q.push({d+1,{nr,nc}});
               }
            }
        }
    }
};
