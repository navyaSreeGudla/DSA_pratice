class Solution {
public:
    int solve(int l, int r,
              vector<int>& newNums,
              vector<vector<int>>& dp) {

        if (r - l == 1)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l + 1; i < r; i++) {

            ans = max(ans,
                      solve(l, i, newNums, dp)
                    + solve(i, r, newNums, dp)
                    + newNums[l] * newNums[i] * newNums[r]);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        vector<int> newNums(n + 2, 1);

        for (int i = 0; i < n; i++)
            newNums[i + 1] = nums[i];

        int m = newNums.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(0, m - 1, newNums, dp);
    }
};