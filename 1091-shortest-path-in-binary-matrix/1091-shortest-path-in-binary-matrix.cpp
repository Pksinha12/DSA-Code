class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        if (grid[0][0] == 0)
        {
            pq.push({0, {0, 0}});
            dist[0][0] = 0;  
        }
        else
            return -1;
        if (n == 1) return 1;
        
        vector<int> delrow = {-1, -1, -1, +0, +1, +1, +1, +0};
        vector<int> delcol = {-1, +0, +1, +1, +1, +0, -1, -1};
                                       
        while (!pq.empty())
        {
            auto it = pq.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            for (int i = 0; i < 8; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m
                   and grid[nrow][ncol] == 0 and dis + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == n-1 and ncol == m-1) return dist[nrow][ncol]+1;
                    pq.push({dist[nrow][ncol],{nrow, ncol}});
                }
            }
            
        }
        return -1;
    }
};