class Solution {
public:
    int f(vector<int> &heights)
    {
        stack<int> st1, st2;
        int n = heights.size();
        vector<int> nseafter(n,-1), nsebefore(n,-1);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (!st1.empty() and heights[st1.top()] >= heights[i]) st1.pop();
            if (!st1.empty()) nseafter[i] = st1.top()-1;
            else nseafter[i] = n-1;
            st1.push(i);
        }
        
        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() and heights[st2.top()] >= heights[i])
                st2.pop();
            if (!st2.empty()) nsebefore[i] = st2.top()+1;
            else nsebefore[i] = 0;
            st2.push(i);
        }

        int maxarea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxarea = max(maxarea, (nseafter[i]-nsebefore[i]+1)*heights[i]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int area = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n,0);
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] == '1') heights[col]++;
                else heights[col] = 0;
            }
            area = max(area, f(heights));
        }
        return area;
    }
};