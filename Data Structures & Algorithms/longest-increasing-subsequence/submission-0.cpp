class Solution {
public:
    int solve(int i,int prev,vector<int>& nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(i == n){
          return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int not_take = solve(i+1,prev,nums,dp);
        int take = 0;
        if(prev == -1 || nums[i]>nums[prev]){
          take = 1+solve(i+1,i,nums,dp);
        }
        return dp[i][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
