class Solution {
public:
    vector<string> letterCombinations(string& digits) {
        if (digits.size()==0)
        return {};
        vector<string> ans;
        string permutation = "";
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, permutation, ans, mapping, digits);
        return ans;
    }
    void solve(int ind, string permutation, vector<string>& ans, vector<string>& mapping, string& digits)
    {
        if (ind >= digits.size())
        {   
            ans.push_back(permutation);
            return;
        }
        int number = digits[ind] - '0';
        string value = mapping[number];
        cout << value;
        for (int i = 0; i < value.size(); i++)
        {
            permutation.push_back(value[i]);
            solve(ind+1, permutation, ans, mapping, digits);
            permutation.pop_back();
        }
    }
};