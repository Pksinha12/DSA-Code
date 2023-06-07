class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            mat[row][col] = dis;
            for (int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and !vis[nrow][ncol])
                {
                    q.push({{nrow, ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
            
            
        }
        return mat;
    }
};