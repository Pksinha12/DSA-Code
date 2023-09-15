class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int s = 0, e = n-1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1])
            {
                return mid;
            }
            else if (arr[mid+1] > arr[mid])
            {
                s = mid+1;
            }
            else if (arr[mid-1] > arr[mid])
            {
                e = mid-1;
            }
        }
        return -1;
    }
};