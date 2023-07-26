class Solution {
public:
    int f(int i, int b, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        int profits = 0;
        if (k == 0) return 0;
        if (i == n) return 0;
        if (dp[i][b][k] != -1) return dp[i][b][k];
        if (b)
        {
            profits = max(prices[i]+f(i+1, 0, k-1, prices, dp), 0+f(i+1, 1, k, prices,dp));
        }
        else
        {
            profits = max(-prices[i]+f(i+1, 1, k, prices, dp), 0+f(i+1, 0, k, prices, dp));
        }
        return dp[i][b][k] = profits;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0, 0, 2, prices, dp);    
    }
};