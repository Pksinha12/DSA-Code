class Solution {
    private:
    int n, m, cnt = 0;
    vector<vector<int>> vis;

    void dfs(int i, int j,const vector<vector<char>>& grid)
    {
        vis[i][j] = 1;
        vector<int> delrows = {-1, 0, 1, 0};
        vector<int> delcols = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nrows = i + delrows[k];
            int ncols = j + delcols[k];
            if (nrows >= 0 and ncols >= 0 and nrows < n and ncols < m and grid[nrows][ncols] == '1' and !vis[nrows][ncols])
                    dfs(nrows, ncols, grid);
        }
        
    }
    public:
    int numIslands(const vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' and !vis[i][j]) 
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};