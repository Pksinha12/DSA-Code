class Solution
{
    public:
        int minCut(string& s)
        {
            int n = s.size();
            if (n == 0 or n == 1) return n-1;
            int i = 0;
            vector<int> dp(n,-1);
            return helper(i, s, dp)-1;
        }
        int helper(int ind, string& s, vector<int>& dp)
        {
            int n = s.size();
            if (ind == n) return 0;
            if (dp[ind] != -1) return dp[ind];
            int mincost = INT_MAX;
            string temp = "";
            for (int j = ind; j < n; j++)
            {
                int cost = 0;
                temp += s[j];
                if (isPalindrome(temp))
                {
                    cost  = 1 + helper(j+1,s, dp);
                    mincost = min(mincost, cost);
                }
            }
            return dp[ind] = mincost;
        }
    bool isPalindrome(string& s)
    {
        int n = s.size();
        for (int i = 0; i < n/2; i++)
        {
            if (s[i] == s[n-i-1]) continue;
            else return false;
        }
        return true;
    }
};