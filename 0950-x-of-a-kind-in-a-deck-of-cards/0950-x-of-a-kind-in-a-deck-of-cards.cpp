class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        int n = deck.size();
        if (n == 1) return false;

        unordered_map<int, int> mp;
        for (auto i : deck)
        {
            mp[i]++;
        }
        int gcd = 0;
        for (auto it : mp)
        {
            gcd = __gcd(gcd, it.second);
        }
        return (gcd > 1);
    }
};