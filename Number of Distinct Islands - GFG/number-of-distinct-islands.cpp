//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private: 
    int rsz, csz;
    set<vector<pair<int,int>>> st;
    void dfs(int row, int col,vector<vector<int>>& grid,const int& brow,const int& bcol, vector<pair<int,int>>& temp)
    {
        if (row < 0 or col < 0 or row >= rsz or col >= csz or grid[row][col] != 1) return;
        
        grid[row][col] = 2;
        temp.push_back({row-brow, col-bcol});
        
        dfs(row-1, col, grid, brow, bcol, temp);
        dfs(row, col+1, grid, brow, bcol, temp);
        dfs(row+1, col, grid, brow, bcol, temp);
        dfs(row, col-1, grid, brow, bcol, temp);
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        rsz = grid.size();
        csz = grid[0].size();
        for (int i = 0; i < rsz; i++)
        {
            for (int j = 0; j < csz; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int,int>> temp;
                    dfs(i, j, grid, i, j, temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends