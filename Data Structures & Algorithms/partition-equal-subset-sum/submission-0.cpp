class Solution {
public:
    bool solve(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        int n = nums.size();
        if(target == 0){
            return true;
        }
        if(i==n){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool not_take = solve(i+1,nums,target,dp);
        bool take  = false;
        if(target>=nums[i]){
            take = solve(i+1,nums,target-nums[i],dp);
        }
        return dp[i][target]=not_take|take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum = sum + nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};
