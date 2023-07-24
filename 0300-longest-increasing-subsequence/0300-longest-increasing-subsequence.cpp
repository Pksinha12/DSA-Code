class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return f(0,-1,nums, dp);
    }
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        int n = nums.size();
        if (ind == n) return 0;
        if (dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int len = 0;
        len = 0 + f(ind+1, prev, nums, dp);
        if (prev == -1 or nums[ind] > nums[prev])
        {
            len = max(len, 1+f(ind+1, ind, nums, dp));
        }
        return dp[ind][prev+1] = len;
    }
};