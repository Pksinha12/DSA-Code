class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        // when we have the circular array 
        // assume linear array and solve the problem 
        // then play indices
        // iterate till 2n and use % n in indexes
        // next greater element from right
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2*n-1; i >= 0; i--)
        {
            if (st.size() == 0) 
            {
                ans[i%n] = -1;
            }
            else
            {
               while (st.size() != 0 and st.top() <= nums[i%n])
                {
                    st.pop();
                }
                if (st.size() > 0)
                ans[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};