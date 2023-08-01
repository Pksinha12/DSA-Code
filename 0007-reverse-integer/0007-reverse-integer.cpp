class Solution {
public:
    int reverse(int x) 
    {
        int rev = 0;
        while (x)
        {
            int r = x % 10;
            if (rev+r/10 > INT_MAX/10 or rev+r/10 < INT_MIN/10) return 0;
            rev = rev*10 + r;
            x = x / 10;
        }
        return rev;
    }
};