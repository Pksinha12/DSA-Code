class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& item1, vector<vector<int>>& item2) 
    {
        vector<vector<int>> ans;
        sort(item1.begin(), item1.end());
        sort(item2.begin(), item2.end());
        int n1 = item1.size();
        int n2 = item2.size();
        int i = 0, j = 0;
        while (i < n1 and j < n2)
        {
            if (item1[i][0] == item2[j][0])
            {
                vector<int> temp = {item1[i][0], item1[i][1]+item2[j][1]};
                ans.push_back(temp);
                i++;
                j++;
            }
            else if (item1[i][0] > item2[j][0])
            {
                ans.push_back({item2[j][0], item2[j][1]});
                j++;
            }
            else
            {
                ans.push_back({item1[i][0], item1[i][1]});
                i++;
            }
        }
        for (; i < n1; i++)
        {
            ans.push_back({item1[i][0], item1[i][1]});
        }
        for (; j < n2; j++)
        {
            ans.push_back({item2[j][0], item2[j][1]});
        }
        return ans;
    }
};