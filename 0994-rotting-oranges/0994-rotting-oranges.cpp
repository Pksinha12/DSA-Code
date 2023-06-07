class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qt;
        // intial configuration 
        int cntFresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    qt.push({{i,j},0});
                    vis[i][j] = 1;
                }
                if (grid[i][j] == 1)
                {
                    cntFresh++;
                }
            }
        }
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int tm = 0;
        int cnt = 0;
        while (!qt.empty())
        {
            int row = qt.front().first.first;
            int col = qt.front().first.second;
            int time = qt.front().second;
            tm = max(tm, time);
            qt.pop();
            
            for (int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if (nrow >=0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0)
                {
                    grid[nrow][ncol] = 2;
                    vis[nrow][ncol] = 1;
                    qt.push({{nrow, ncol}, time+1});
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
            return -1;
        return tm;
    }
};