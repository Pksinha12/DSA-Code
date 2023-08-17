class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newIntervals) 
    {
        vector<vector<int>> ans;
        int n = v.size();
        int i = 0;
        while (i < n and v[i][1] < newIntervals[0]) 
        {
            ans.push_back(v[i]);
            i++;
        }
        vector<int> mI = newIntervals;
        while (i< n and v[i][0] <= newIntervals[1])
        {
            mI[0] = min(mI[0], v[i][0]);
            mI[1] = max(mI[1], v[i][1]);
            i++;
        }
        ans.push_back(mI);
        while (i < n) 
        {
            ans.push_back(v[i]);
            i++;
        }
        return ans;
    }
};