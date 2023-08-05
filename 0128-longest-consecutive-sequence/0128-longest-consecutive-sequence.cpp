class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
       unordered_set<int> st;
        for (auto i : nums)
        {
            st.insert(i);
        }
        int mx = 1;
        for(auto it : st)
        {
           if (st.find(it-1) == st.end())
           {
               int x = it;
               int cnt = 1;
               while (st.find(x+1) != st.end())
               {
                   x++;
                   cnt++;
               }
               mx = max(mx, cnt);
           }
        }
        return mx;
    }
};