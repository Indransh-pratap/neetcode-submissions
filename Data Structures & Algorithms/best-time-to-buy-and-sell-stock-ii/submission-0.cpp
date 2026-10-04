class Solution {
    int soln(vector<int>& prices, int buy, vector<vector<int>>& dp, int idx) {
        int profit = 0;
        if (idx == prices.size()) return 0;

        //

        if (dp[idx][buy] != -1) return dp[idx][buy];
        if (buy) {
            profit = max(-prices[idx] + soln(prices, 0, dp, idx + 1), soln(prices, 1, dp, idx + 1));
        }

        else {
            profit = max(prices[idx] + soln(prices, 1, dp, idx + 1), soln(prices, 0, dp, idx + 1));
        }

        return dp[idx][buy] = profit;
    }

   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return soln(prices, 1, dp, 0);
    }
};