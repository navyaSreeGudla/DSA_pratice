class Solution {
public:
    int solve(int i,vector<int>& dp,vector<int>& nums){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = nums[i]+solve(i-2,dp,nums);
        int not_take = solve(i-1,dp,nums);
        return dp[i]=max(not_take,take);
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};
