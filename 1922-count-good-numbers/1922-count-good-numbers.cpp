typedef long long ll;
long long mod = 1e9+7;
class Solution {
public:
    long long power(long long num, long long times)
    {
        long long ans = 1l;
        while (times != 0)
        {
            if (times % 2 == 1)
            {
                ans = (ans % mod * num % mod) % mod;
                times = times-1;
            }
            else
            {
                num = (num%mod*num%mod)%mod;
                times = times/2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) 
    {
       long long fours = n/2;
       long long fives = n - n/2;
        return (power(4,fours)*power(5,fives))%mod;
    }
};