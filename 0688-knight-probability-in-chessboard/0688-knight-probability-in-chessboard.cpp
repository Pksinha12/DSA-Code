class Solution {
public:
    double f(int n, int k, int row, int col, vector<vector<vector<double>>>& dp)
    {
        if (k == 0) return 1;
        if (dp[row][col][k] != 0) return dp[row][col][k];
        int delrow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int delcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        double choicei = 0.0;
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < n)
            {
                choicei += 0.125*f(n, k-1, nrow, ncol, dp);
            }
        }
        dp[row][col][k] = choicei;
        return dp[row][col][k];
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1, 0)));
        return f(n, k, row, col, dp);
        // string s = to_string(row) + to_string(col) + to_string(k);
    }
};