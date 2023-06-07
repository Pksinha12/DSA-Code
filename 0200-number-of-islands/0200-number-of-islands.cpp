class Solution {
    private:
    int n, m, cnt = 0;
    vector<vector<int>> vis;

    void bfs(int i, int j, const vector<vector<char>>& grid)
    {
        queue<pair<int,int>> qt;
        qt.push({i, j});
        //vis[i][j] = 1;
        
        while (!qt.empty())
        {
            int row = qt.front().first;
            int col = qt.front().second;
            vis[row][col] = 1;
            qt.pop();
            vector<int> delrows = {-1, 0, 1, 0};
            vector<int> delcols = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int nrows = row + delrows[k];
                int ncols = col + delcols[k];
                if (nrows >= 0 and ncols >= 0 and nrows < n and ncols < m and grid[nrows][ncols] == '1' and !vis[nrows][ncols])
                {
                    qt.push({nrows, ncols});
                    vis[nrows][ncols] = 1;
                }
                    
            }
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
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};