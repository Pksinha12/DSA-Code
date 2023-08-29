class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if (row == 0 and col == 0) return grid[0][0];
        if (dp[row][col] != -1) return dp[row][col];
        int choice1 = INT_MAX, choice2 = INT_MAX;
        if (row-1>=0)
        choice1 =  f(row-1, col, grid, dp) + grid[row][col];
        if (col-1>=0)
        choice2 = f(row, col-1, grid, dp) + grid[row][col];
        return dp[row][col] = min(choice1, choice2);
        
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
        return f(m-1, n-1, grid, dp);
    }
};