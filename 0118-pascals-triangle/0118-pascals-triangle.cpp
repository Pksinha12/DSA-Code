class Solution {
public:
    void nCr(int n, vector<vector<int>>& ans)
    {
        vector<int> temp(n);
        int cur = 1;
        temp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            cur = cur*(n-i)/i;
            temp[i] = cur;
        }
        ans.push_back(temp);
    }
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++)
        {
            nCr(i, ans);
        }
        return ans;
    }
};