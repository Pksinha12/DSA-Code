class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        int res = 0;
        for (int i = 0; i < m; i++) 
        {
            ans[0][i] = matrix[0][i];
            res += ans[0][i];
        }
        for (int i = 0; i < n; i++) 
        {
            ans[i][0] = matrix[i][0];
            res += ans[i][0];
        }
        res -= ans[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j]==1)
                ans[i][j] = min(ans[i-1][j-1], min(ans[i-1][j], ans[i][j-1]))+1;
                else ans[i][j] = 0;
                res += ans[i][j];
            }
        }
        return res;
    }
};