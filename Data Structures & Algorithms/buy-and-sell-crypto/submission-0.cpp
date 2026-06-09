class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int min_cost = prices[0];
        for(int i =1;i<n;i++){
           int cost = prices[i]-min_cost;
           min_cost = min(min_cost,prices[i]);
           profit = max(cost,profit);
        }
        return profit;
    }
};
