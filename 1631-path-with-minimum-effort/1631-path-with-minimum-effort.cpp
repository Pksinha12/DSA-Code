class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue< pair<int,pair<int,int>>,
        vector< pair<int,pair<int,int>> >,
        greater< pair<int,pair<int,int>> > >pq;
        vector<vector<int>> minDiff(n, vector<int>(m, 1e9));
        
        pq.push({0, {0, 0}});
        minDiff[0][0] = 0;
        
        vector<int> delcol = {-1, 0, 1, 0};
        vector<int> delrow = {0, 1, 0, -1};
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == n-1 and col == m-1) return diff;
            for (int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m)
                {
                    int maxEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                    if (maxEffort < minDiff[nrow][ncol])
                    {
                        minDiff[nrow][ncol] = maxEffort;
                        pq.push({maxEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};