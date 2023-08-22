class Solution {
public:
    bool isValid(string s) 
    {
        //understand the problem read, i/p, o/p, constraints
        // identification ------brute force 
        // build approach ------better approach we use some kind of data structure to improve time complexity;
        // code and dry run parrallely
        // optimize for edge cases and corner cases;
        
        // the given question can be better improved by stack;
        // movement from right to left;
        // use stack to search for every closing bracket
        int n = s.size();
        stack <int> st;
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == ')' or s[i] == '}' or s[i] == ']')
            {
                st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                if (st.size() == 0) return false;
                else if (st.top() == ')') 
                {
                    st.pop();
                }
                else return false;
            }
            else if (s[i] == '{')
            {
                if (st.size() == 0) return false;
                else if (st.top() == '}') 
                {
                    st.pop();
                }
                else return false;
            }
            else if (s[i] == '[')
            {
                if (st.size() == 0) return false;
                else if (st.top() == ']') 
                {
                    st.pop();
                }
                else return false;
            }
        }
        if (st.size() > 0) return false;
        return true;
    }
};