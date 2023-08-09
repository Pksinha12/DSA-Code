class Solution {
public:
    int strStr(string str, string key) 
    {
        int m = key.size();
        int n = str.size();
        //sliding window technique
        int left = 0, right = 0;
        while (right < n)
        {
            while (right-left+1 < m)
            {
                right++;
            }
            if (str.substr(left, right-left+1) == key)
            {
                return left;
            }
            left++;
        }
        return -1;
    }
};