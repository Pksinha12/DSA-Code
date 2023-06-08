//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) // column
        {
            if (!vis[i][0] and board[i][0] == 'O')
                dfs(i, 0, vis, board);
            if (!vis[i][m-1] and board[i][m-1] == 'O')
                dfs(i, m-1, vis, board);
        }
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] and board[0][j] == 'O')
                dfs(0, j, vis, board);
            if (!vis[n-1][j] and board[n-1][j] == 'O')
                dfs(n-1, j, vis, board);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return board;
    }
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if (nrow >= 0 and nrow >= 0 and nrow < n and ncol < m and !vis[nrow][ncol] and board[nrow][ncol] == 'O')
                dfs(nrow, ncol, vis, board);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends