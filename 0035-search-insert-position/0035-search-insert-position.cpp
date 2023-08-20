class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        //binary search questions because array is sorted;
        int n = nums.size();
        int s = 0, e = n-1;
        int res = 0;
        while (s <= e)
        {
            int mid = s + (e-s)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                res = mid;
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        if (s == -1 or e == -1) return 0;
        return res+1;
    }
};