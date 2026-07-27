class Solution {
public:
    int solve(int i, vector<int>& prices, bool bought,
              vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][bought] != -1)
            return dp[i][bought];

        if (!bought) {
            int notBuy = solve(i + 1, prices, false, dp);
            int buy = -prices[i] + solve(i + 1, prices, true, dp);

            return dp[i][bought] = max(notBuy, buy);
        }

        int notSell = solve(i + 1, prices, true, dp);
        int sell = prices[i] + solve(i + 2, prices, false, dp);

        return dp[i][bought] = max(notSell, sell);
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, prices, false, dp);
    }
};