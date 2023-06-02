class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }
        int ps = pattern.size();
        int strs = words.size();
        if (ps != strs) return false;
        for (int i = 0; i < ps; i++)
        {
            mp1[pattern[i]] = words[i];
        }
        for (int i = 0; i < strs; i++)
        {
            mp2[words[i]] = pattern[i];
        }
        for (int i = 0; i < min(ps,strs); i++)
        {
            if (mp1[pattern[i]] != words[i] or mp2[words[i]] != pattern[i])
                return false;
        }
        return true;
    }
};