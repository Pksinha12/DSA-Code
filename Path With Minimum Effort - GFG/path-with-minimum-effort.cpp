//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue< pair<int,pair<int,int>>,
        vector< pair<int,pair<int,int>> >,
        greater< pair<int,pair<int,int>> > >pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        
        while (!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            if (row == n-1 and col == m-1) return diff;
            for (int k = 0; k < 4; k++)
            {
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                
                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m)
                {
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
     return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends