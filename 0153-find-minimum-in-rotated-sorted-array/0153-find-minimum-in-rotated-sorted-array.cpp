class Solution {
public:
    int findMin(vector<int>& nums)
    {
        //again a binary search questions
        // index of minimum nuber will number of times rotated array;
        int n = nums.size();
        
        int s = 0, e = n-1;
        while (s <= e)
        {
            int mid = s + (e-s)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if (nums[s] <= nums[e]) return nums[s];
            if (nums[mid] <= nums[prev] and nums[mid] <= nums[next])
            {
                return nums[mid];
            }
            else if (nums[mid] >= nums[s])
            {
                s = mid+1;
                cout  << s << " ";
            }
            else if (nums[mid] <= nums[e])
            {
                e = mid-1;
                //cout << e;            
            }
        }
        return nums[s];
    }
};