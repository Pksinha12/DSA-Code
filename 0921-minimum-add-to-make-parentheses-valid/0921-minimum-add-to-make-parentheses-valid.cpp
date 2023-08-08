class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> stk;
        int cnt = 0;
        int n = s.size();
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == '(') 
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    cnt++;
                }
            }
            else
            {
                stk.push(')');
            }
                
        }
        return stk.size()+cnt;
    }
};