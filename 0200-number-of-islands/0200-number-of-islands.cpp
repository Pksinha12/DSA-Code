class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vector<int> delrows = {-1, 0, 1, 0};
        vector<int> delcols = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nrows = i + delrows[k];
            int ncols = j + delcols[k];
            if (nrows >= 0 and ncols >= 0 and nrows < n and ncols < m)
            {
                if (grid[nrows][ncols] == '1' and !vis[nrows][ncols]) 
                    dfs(nrows, ncols, vis, grid);
            
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' and !vis[i][j]) 
                {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};