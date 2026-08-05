class Solution {
public:
    bool solve(int i,int j,string s,string p,vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();
        if(j == m){
            return i == n;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool match = ((i<n) && (s[i]==p[j] || p[j]=='.'));
        if(j+1<m && p[j+1]=='*'){
            return dp[i][j] = solve(i,j+2,s,p,dp)||(match && solve(i+1,j,s,p,dp));
        }
        if(match){
            return dp[i][j] = solve(i+1,j+1,s,p,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,p,dp);
    }
};
