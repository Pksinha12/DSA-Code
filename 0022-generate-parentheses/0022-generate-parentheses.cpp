class Solution {
public:
    void f(int open, int close, string& temp, vector<string>& ans)
    {
        if (open == 0 and close == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (open != 0)
        {
            temp.push_back('(');
            f(open-1, close, temp, ans);
            temp.pop_back();
        }
        
        if (close > open)
        {
            temp.push_back(')');
            f(open, close-1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        int open = n, close = n;
        string temp = "";
        vector<string> ans;
        f(open, close, temp, ans);
        return ans;
    }
};