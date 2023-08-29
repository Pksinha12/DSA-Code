class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp)
    {
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];
         int choice1 = f(ind-2, nums, dp) + nums[ind];
         int choice2 = f(ind-1, nums, dp) + 0;
        return dp[ind] = max(choice1, choice2);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};