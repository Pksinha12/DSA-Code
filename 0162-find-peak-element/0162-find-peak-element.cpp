class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // binary search 
        // how to move and condition
        // edge case
        int n = arr.size();
        if (n == 1) return 0;
        int s = 0, e = n-1;
        while (s <= e)
        {
            int mid = s + (e-s)/2;
            if (mid > 0 and mid < n-1)
            {
                if (arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return mid;
                else if (arr[mid] < arr[mid+1]) s = mid+1;
                else if (arr[mid] < arr[mid-1]) e = mid-1;
            }
            else if (mid == 0)
            {
                if (arr[mid] > arr[mid+1]) return mid;
                else return mid+1;
            }
            else if (mid == n-1)
            {
                if (arr[mid] > arr[mid-1]) return mid;
                else return mid-1;
            }
            
        }
        return -1;
    }
};