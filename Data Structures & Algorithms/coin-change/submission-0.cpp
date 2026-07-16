class Solution {
public:
    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        if (i < 0)
            return INT_MAX;

        int not_take = solve(i - 1, coins, amount);

        int take = INT_MAX;
        if (amount >= coins[i]) {
            int res = solve(i, coins, amount - coins[i]);
            if (res != INT_MAX)
                take = 1 + res;
        }

        return min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins.size() - 1, coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};