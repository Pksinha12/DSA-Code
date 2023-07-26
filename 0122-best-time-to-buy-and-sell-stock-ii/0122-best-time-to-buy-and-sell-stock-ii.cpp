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
        //vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> next(2,0), curr(2,0);
        // Tabulation
        // write down base case
        // assigned zero to dp hence no need to write base case
        // start for loop for the changing variables
        for (int i = n-1; i >= 0; i--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int profits = 0;
                if (buy)
                {
                   profits =  max(prices[i] + next[0], 0 + next[1]);
                }
                else
                {
                   profits = max(-prices[i]+next[1],  0 + next[0]);
                }
                curr[buy] = profits;
            }
            next = curr;
        }
        return curr[0];
    }
};