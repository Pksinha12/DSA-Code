class Solution {
public:
    int f(int i1, int i2, string& text1, string& text2, vector<vector<int>>& dp)
    {
        if (i1 == text1.size() or i2 == text2.size()) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        int ans = 0;
        if (text1[i1] == text2[i2])
        {
            ans = 1+f(i1+1, i2+1, text1, text2, dp);
        }
        else
        {
            ans = max(0+f(i1+1, i2, text1, text2, dp), 0+f(i1, i2+1, text1, text2, dp));
        }
        return dp[i1][i2] = ans;
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(0, 0, text1, text2, dp);
    }
};