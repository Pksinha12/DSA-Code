class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<long long>>& dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (row >= m or col >= n) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
        if (row+1 < m and row+1 >= 0 and
            col+1 < n and col+1 >= 0 and 
            grid[row+1][col+1] > grid[row][col])
        cnt1 = 1+f(row+1, col+1, grid, dp);
        if (row-1 < m and row-1 >= 0 and
            col+1 < n and col+1 >= 0 and 
            grid[row-1][col+1] > grid[row][col])
        cnt2 =1+ f(row-1, col+1, grid, dp);
        if (row < m and row >= 0 and
            col+1 < n and col+1 >= 0 and 
            grid[row][col+1] > grid[row][col])
        cnt3 =1+f(row, col+1, grid, dp);
        return dp[row][col] = max(cnt1, max(cnt2,cnt3));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, f(i, 0, grid, dp));
        }
        return ans;
    }
};