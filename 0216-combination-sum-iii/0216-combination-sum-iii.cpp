class Solution {
public:
    void f(int ind, int k, int n, vector<int>& op, vector<vector<int>>& ans)
    {
        if (k == 0)
        {
            if (n == 0)
            {
                ans.push_back(op);
            }
            return;
        }
        for (int i = ind; i <= 9; i++)
        {
            op.push_back(i);
            f(i+1, k-1, n-i, op, ans);
            op.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> op;
        f(1,k, n, op, ans);
        return ans;
    }
};