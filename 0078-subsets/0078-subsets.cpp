class Solution {
public:
    void f(int ind, vector<int>& temp, vector<vector<int>>& ans, vector<int>&nums)
    {
        if (ind < 0)
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ind]);
        f(ind-1, temp, ans, nums);
        temp.pop_back();
        
        f(ind-1, temp, ans, nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        f(n-1, temp, ans, nums);
        return ans;
    }
};