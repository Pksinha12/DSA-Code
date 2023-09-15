class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size();
        unordered_map<int, int> mp;
        // sliding window problem;
        int left = 0, right = 0;
        int max_count = INT_MIN;
        while (right < n)
        {
            
            while (right < n and mp.size() <= 2)
            {
                mp[fruits[right]]++;
                right++;
            }
            
            if (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            max_count = max(right-left, max_count);
        }
        return max_count;
    }
};