class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> maxLeft(n,-1), maxRight(n,-1);
        maxLeft[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        maxRight[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            maxRight[i] = max(height[i], maxRight[i+1]);
        }
        // water collected per building will be 
        // min(maxRight, maxLeft)- height[i] * 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(maxRight[i], maxLeft[i]) - height[i];
        }
        return ans;
    }
};