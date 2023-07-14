class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        vector<int> dp(n,-1);
        return helper(0, arr, k, dp);
    }
    int helper(int i, vector<int>& arr, int k, vector<int>& dp)
    {
        int n = arr.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        for (int j = i; j < min(i+k, n); j++)
        {
            maxi = max(maxi, arr[j]);
            int sum = maxi*(j-i+1) + helper(j+1, arr, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
};