class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp)
    {
        // explore all possiblities 
        // he has bought the stock previously so he can just sell it now or do not sell it but surely he can buy it now
        // he has not bought the stock previously so he cam just buy it now or do not buy 
        int n = prices.size();
        if (i == n) return 0;
        if (dp[i][buy]!=-1) return dp[i][buy];
        int profits = 0;
        if (buy == 1)
        {
           
           profits =  max(prices[i] + f(i+1, 0, prices, dp), 0 + f(i+1, 1, prices, dp));
        }
        else
        {
           profits = max(-prices[i]+f(i+1, 1, prices, dp),  0 + f(i+1, 0, prices, dp));
        }
        return dp[i][buy] = profits;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 0, prices, dp);
    }
};