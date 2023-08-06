class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        int n = prices.size();
        int mx = INT_MIN;
        for (int i = n-1; i >= 0; i--)
        {
            if (prices[i] > mx)
            {
                mx = prices[i];
                int mini = *min_element(prices.begin(), prices.begin()+i);
                ans = max(ans, mx - mini);
            }
        }
        return ans;
    }
};