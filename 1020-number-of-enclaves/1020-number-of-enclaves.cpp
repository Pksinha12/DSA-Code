class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>& grid)
    {
        int rsz = grid.size();
        int csz = grid[0].size();
        if (row < 0 or col < 0 or row >= rsz or col >= csz ) return;
        if (grid[row][col] != 1) return;
        
        grid[row][col] = 2;
        
        dfs(row, col+1, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row-1, col, grid);
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int rsz = grid.size();
        int csz = grid[0].size();
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