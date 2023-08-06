class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        int odd = 1, even = 0;
        vector<int> ans(n);
        int ind = 0;
        while (ind < n)
        {
            if (nums[ind] >= 0)
            {
                ans[even] = nums[ind];
                even+=2;
            }
            else
            {
                ans[odd] = nums[ind];
                odd+=2;
            }
            ind++;
        }
        return ans;
    }
};