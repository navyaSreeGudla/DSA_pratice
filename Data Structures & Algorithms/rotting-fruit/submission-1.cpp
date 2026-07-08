class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int count = 0;
        int time = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count == 0){
                return time;
            }
        while(!q.empty()){
            int sz = q.size();
            while(sz){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};
            for(int i =0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    count--;
                }
            }
            sz--;
            }
            time++;
        }
        if(count ==0){
            return time-1;
        }
        return -1;
    }
};
