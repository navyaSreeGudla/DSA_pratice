class Solution {
public:
    bool solve(int i, vector<int>& nums) {
        int n = nums.size();

        if (i == n - 1)
            return true;

        if (nums[i] == 0)
            return false;

        for (int k = 1; k <= nums[i] && i + k < n; k++) {
            if (solve(i + k, nums))
                return true;
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(0, nums);
    }
};