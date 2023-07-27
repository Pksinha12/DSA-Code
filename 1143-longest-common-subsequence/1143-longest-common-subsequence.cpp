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
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // tabulation
        for (int i1 = n1-1; i1 >= 0; i1--)
        {
            for (int i2 = n2-1; i2>=0; i2--)
            {
                int ans = 0;
                if (text1[i1] == text2[i2])
                {
                    ans = 1+dp[i1+1][i2+1];
                }
                else
                {
                    ans = max(0+dp[i1+1][i2], 0+dp[i1][i2+1]);
                }
                dp[i1][i2] = ans;
            }
        }
        return dp[0][0];
    }
};