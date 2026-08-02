class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,int prev,vector<vector<int>>& dp){
       int n = matrix.size();
       int m = matrix[0].size(); 
       if(i<0 || i>=n || j<0 ||j>=m||matrix[i][j]<=prev){
        return 0;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       int res =1;
       vector<int>dr = {-1,0,1,0};
       vector<int>dc = {0,1,0,-1};
       for(int d = 0;d<4;d++){
        res = max(res,1+dfs(matrix,i+dr[d],j+dc[d],matrix[i][j],dp));
       }
       dp[i][j]=res;
       return res;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                res = max(res,dfs(matrix,i,j,INT_MIN,dp));
            }
        }
        return res;
    }
};
