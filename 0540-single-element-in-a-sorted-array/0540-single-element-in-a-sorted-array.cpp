class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
       int p1 = 0,p2 = nums.size()-1;
        while(p1 < p2){
            int mid = (p1 + p2) / 2;
            if(mid & 1){
                mid--;
            }
            if(nums[mid] == nums[mid + 1]){
                p1 = mid + 2;
            }
            else{
                p2 = mid - 1;
            }
        }
        return nums[p1];
    }
};