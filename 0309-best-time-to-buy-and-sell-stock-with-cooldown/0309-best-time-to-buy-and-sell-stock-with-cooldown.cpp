class Solution {
public:
    int f(int i, int b, vector<int>& w, vector<vector<int>>& dp)
    {
        int n = w.size();
        int profits = 0;
        if (i >= n) return 0;
        if (dp[i][b] != -1) return dp[i][b];
        if (b)
        {
            profits = max(w[i]+f(i+2, 0, w, dp), 0+f(i+1, 1, w,dp));
        }
        else
        {
            profits = max(-w[i]+f(i+1, 1, w, dp), 0+f(i+1, 0, w, dp));
        }
        return dp[i][b] = profits;
    }
    int maxProfit(vector<int>& w) 
    {
        int n = w.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return f(0, 0, w, dp);  
    }
};