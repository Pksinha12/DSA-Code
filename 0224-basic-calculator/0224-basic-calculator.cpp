class Solution {
public:
    int calculate(string s) {
        stack<long long> signs;
        long long sign = 1;
        long long num = 0;
        long long ans = 0;
        
        // always transform s into ( s )
        signs.push(1);
        
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }
        
        if (num) {
            ans = ans + signs.top() * sign * num;
        }
        
        return ans;
    }
};