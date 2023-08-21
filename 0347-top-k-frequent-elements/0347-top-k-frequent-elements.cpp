class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for (auto i : mp)
        {
            minHeap.push({i.second, i.first});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        while (minHeap.size() > 0)
        {
            int temp = minHeap.top().second;
            ans.push_back(temp);
            minHeap.pop();
        }
        return ans;
    }
};