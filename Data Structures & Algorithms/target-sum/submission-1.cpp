class Solution {
public:
    int solve(int i, vector<int>& nums, int target){

        if(i == nums.size())
            return target == 0;

        int add = solve(i + 1, nums, target - nums[i]);

        int sub = solve(i + 1, nums, target + nums[i]);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};