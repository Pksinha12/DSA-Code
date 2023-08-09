class Solution {
public:
    int f(int ind, int amt, vector<int>& coins, vector<vector<int>> &dp)
    {
        if (amt == 0) return 1;
        if (ind < 0) return 0;
        if (dp[ind][amt] != -1) return dp[ind][amt];
        int included = 0, excluded = 0;
        if (coins[ind] <= amt)
        included = f(ind, amt - coins[ind], coins, dp);
        excluded = f(ind-1, amt, coins, dp);
        return dp[ind][amt] = included+excluded;
    }
    int change(int amt, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amt+1, -1));
        return f(n-1, amt, coins, dp);
    }
};