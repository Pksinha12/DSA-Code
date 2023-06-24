class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<pair<int, int>> rightIdx, leftIdx;
        vector<int> right(n,-1), left(n,-1);
        for (int i = 0; i < n; i++)
        {
            while (!leftIdx.empty() and leftIdx.top().second >= heights[i])
            {
                leftIdx.pop();
            }
            if (leftIdx.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = leftIdx.top().first+1;
            }
            leftIdx.push({i, heights[i]});
        }
        for (int i = n-1; i >= 0; i--)
        {
            while (!rightIdx.empty() and rightIdx.top().second >= heights[i])
            {
                rightIdx.pop();
            }
            if (rightIdx.empty())
            {
                right[i] = heights.size()-1;
            }
            else
            {
                right[i] = rightIdx.top().first-1;
            }   
            rightIdx.push({i, heights[i]});
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, (right[i]-left[i]+1)*heights[i]);
        }
        return maxi;
    }
};