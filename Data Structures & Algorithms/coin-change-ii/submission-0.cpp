class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        int n = coins.size();
        if(amount == 0){
            return 1;
        }
        if(i>=n || amount<0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int not_take = solve(i+1,coins,amount,dp);
        int take = 0;
        if(amount>=coins[i]){
           take = solve(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount]=not_take +take;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,coins,amount,dp);
    }
};
