class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int min_elem = *min_element(ranks.begin(), ranks.end());
        unsigned long long int max_time = 1e14;
        // this question is of binary search on answers;
        long long int s = 1, e = max_time;
        long long ans = 1e18;
        while (s <= e)
        {
            long long int mid = s + (e-s)/2;
            long long int cars_done = 0;
            for (int i = 0; i < ranks.size(); i++)
            {
                cars_done += sqrt(mid/ranks[i]);
            }
            if (cars_done >= cars)
            {
                e = mid-1;
                if (mid < ans)
                {
                    ans = mid;
                }
                else
                {
                    return ans;
                }
                
            }
            else if (cars_done < cars)
            {
                s = mid+1;
            }
        }
        return s;
    }
};