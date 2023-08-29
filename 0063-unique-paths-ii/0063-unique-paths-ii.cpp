class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if (row == 0 and col == 0) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        int up = 0, left = 0;
        if (col-1 >= 0 and grid[row][col-1] == 0)
        left = f(row, col-1, grid, dp);
        if (row-1 >= 0 and grid[row-1][col] == 0)
        up = f(row-1, col, grid, dp);
        return dp[row][col] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 or grid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, grid, dp);
    }
};