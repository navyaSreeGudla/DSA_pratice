class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});
        
        while(!pq.empty()){
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(t > dist[r][c]) continue;
            if(r == n-1 && c == m-1) return t;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newTime = max(t, grid[nr][nc]);
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};