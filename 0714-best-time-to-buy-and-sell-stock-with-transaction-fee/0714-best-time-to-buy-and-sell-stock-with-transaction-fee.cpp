class Solution {
public:
     int f(int i, int b, vector<int>& prices, int fee, vector<vector<int>>& dp)
    {
        int n = prices.size();
        int profits = 0;
        if (i >= n) return 0;
        if (dp[i][b] != -1) return dp[i][b];
        if (b)
        {
            profits = max(prices[i]-fee+f(i+1, 0, prices, fee, dp), 0+f(i+1, 1, prices, fee, dp));
        }
        else
        {
            profits = max(-prices[i]+f(i+1, 1, prices, fee, dp), 0+f(i+1, 0, prices, fee, dp));
        }
        return dp[i][b] = profits;
    }
   
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return f(0, 0, prices, fee, dp);  
    }
};