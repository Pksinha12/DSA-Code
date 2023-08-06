class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxsum = INT_MIN;
        int sum = 0;
        int n = nums.size();
        int ind = 0;
        while (ind < n)
        {
            sum += nums[ind];
            if (sum > maxsum)  maxsum = sum;
            if (sum < 0) sum = 0;
            ind++;
        }
        return maxsum;
    }
};