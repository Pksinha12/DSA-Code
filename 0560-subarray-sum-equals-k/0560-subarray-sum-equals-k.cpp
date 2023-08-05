class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int presum = 0, ans = 0;
        for (auto i : nums)
        {
            presum += i;
            int rem = presum - k;
            ans += mp[rem];
            mp[presum]++;
        }
        return ans;
    }
};