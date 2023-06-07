class Solution {

    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)    
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int intialColor = image[sr][sc];
        if (intialColor == newcolor) return image;
        image[sr][sc] = newcolor;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and image[nrow][ncol] == intialColor)
                {
                    image[nrow][ncol] = newcolor;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};