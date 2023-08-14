class Solution {
public:
    string minWindow(string s, string t) 
    {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> mp, copy;
        for (auto i : t)
        {
            mp[i]++;
        }
        int count = mp.size();
        int left = 0, right = 0;
        int n = s.size();
        int ans = INT_MAX;
        int start = -1, end = -1;
        while (left <= right and left < n)
        {
            while (count != 0 and right < n)
            {
                if (mp.find(s[right]) != mp.end()) 
                {
                    mp[s[right]]--;
                    if (mp[s[right]] == 0) count--;
                }
                right++;
            }
            
            if (count == 0)
            {
                if (ans > right-left)
                {
                    ans = right-left;
                    end = right;
                    start = left;
                }
            }
            
            if (mp.find(s[left]) != mp.end()) 
            {
                mp[s[left]]++;
                if (mp[s[left]] > 0) count++;
            }
            left++;
        }
        if (start == -1) return "";
        return s.substr(start, ans);
    }
};