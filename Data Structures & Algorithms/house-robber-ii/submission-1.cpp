class Solution {
public:
    int solve(int i,int start,vector<int>& dp,vector<int>& nums){
        if(i<start){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = nums[i]+solve(i-2,start,dp,nums);
        int not_take = solve(i-1,start,dp,nums);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n==1){
            return nums[0];
        }
        return max(solve(n-2,0,dp1,nums),solve(n-1,1,dp2,nums));
    }
};
