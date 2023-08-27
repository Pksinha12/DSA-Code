class Solution {
public:
    vector<string> op;
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(string& str)
    {
        int m = str.size();
        for (int i = 0;  i <= m/2; i++)
        {
            if (str[i] != str[m-i-1]) return false;
        }
        return true;
    }
    void f(int ind, string& ip)
    {
        if (ind >= n)
        {
            ans.push_back(op);
            return ;
        }
        for (int i = ind; i < ip.size(); i++)
        {
            string s = ip.substr(ind, i-ind+1);
            if (isPalindrome(s))
            {
                op.push_back(s);
                f(i+1, ip);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string& ip) 
    {
        n = ip.size();
        f(0, ip);
        return ans;
    }
};