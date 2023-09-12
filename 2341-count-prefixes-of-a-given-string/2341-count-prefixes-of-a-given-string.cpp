class Solution {
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        unordered_map<string, int> mp;
        for (auto i : words)
        {
            mp[i]++;
            // cout << i << " " << mp[i] << " " << endl;
        }
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            string str = s.substr(0, i+1);
            cout << str << " " << endl;
            if (mp.find(str) != mp.end())
            {
                cnt += mp[str];
                // cout << cnt << " " << endl;
            }
        }
        return cnt;
    }
};