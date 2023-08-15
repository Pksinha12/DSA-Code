class Solution {
public:
    inline int search(const vector<int>& nums, const int& target)
    {
       // algorithm 
        // find which half is sorted 
        // then keys lies in sorted half or other
        // eliminate other half
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;
        while (low <= high)
        {
            mid = low + (high - low)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[low] <= nums[mid]) // left half is sorted
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            else
            {
                if (nums[mid] <= target and target <= nums[high])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};