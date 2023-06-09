class Solution {
    private:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    int rsz, csz;
    void dfs(int row, int col, vector<vector<int>>& grid)
    {
        grid[row][col] = 2; 
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if (nrow >= 0 and ncol >= 0 and nrow < rsz and ncol < csz and grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, grid);
            }
                
        } 
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        rsz = grid.size();
        csz = grid[0].size();
        for (int i = 0; i < csz; i++)
        {
            if (grid[0][i] == 1) dfs(0, i, grid);
            if (grid[rsz-1][i] == 1) dfs(rsz-1, i, grid);
        }
        for (int i = 0; i < rsz; i++)
        {
            if (grid[i][0] == 1) dfs(i, 0, grid);
            if (grid[i][csz-1] == 1) dfs(i, csz-1, grid);
        }
        int ans = 0;
        for (int i = 0; i < rsz; i++)
        {
            for (int j = 0; j < csz; j++)
            {
                if (grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};