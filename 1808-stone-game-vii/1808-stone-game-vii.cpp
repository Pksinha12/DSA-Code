class Solution {
public:
    int solve(int i, int j, int sum, vector<int>& stones, vector<vector<int>>& dp)
    {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(sum - stones[i] - solve(i+1, j, sum-stones[i], stones, dp),
                              sum-stones[j] - solve(i, j-1, sum-stones[j], stones, dp));
    }
    int stoneGameVII(vector<int>& stones) 
    {
        int n = stones.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += stones[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, sum, stones, dp);
    }
};