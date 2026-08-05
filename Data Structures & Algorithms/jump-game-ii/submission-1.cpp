class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(i == n-1){
            return 0;
        }
        if(i!=n-1 && nums[i]==0){
            return INT_MAX/2;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini = INT_MAX;
        for(int k = 1;k<=nums[i] && i+k<n ;k++){
           int res = 1+solve(i+k,nums,dp);
           mini = min(res,mini); 
        }
        return dp[i] =mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};
