class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
        {
            int key = target - numbers[i];
            int left = i+1;
            int right = numbers.size();
            int middle = left + (right - left) / 2;
            while (left < right)
            {
                middle = left + (right - left) / 2;
                if (numbers[middle] < key)
                {
                    left = middle + 1;
                }
                else if (numbers[middle] > key)
                {
                    right = middle;
                }
                else
                {
                    return {i+1,middle+1};
                }
            }
        }
        return {-1,-1};
    }
};