class Solution {
public:
    int f(int i1, int i2, string& s1, string& s2, vector<vector<int>>& dp)
    {
        if (i1 == s1.size() or i2 == s2.size()) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        int ans = 0;
        if (s1[i1] == s2[i2])
        {
            ans = 1+f(i1+1, i2+1, s1, s2, dp);
        }
        else
        {
            ans = max(0+f(i1+1, i2, s1, s2, dp), 0+f(i1, i2+1, s1, s2, dp));
        }
        return dp[i1][i2] = ans;
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0, 0, s, s1, dp);
    }
};