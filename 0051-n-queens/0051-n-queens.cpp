class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        string s(n, '.');
        vector<string> board(n,s);
        vector<vector<string>> ans;
        f(0, n, board, ans);
        return ans;
    }
    void f(int col, int n,  vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                f(col+1, n, board, ans);
                board[row][col] = '.';
            }
            
        }
        return;
    }
    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        int trow = row;
        int tcol = col;
        
        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        row = trow;
        col = tcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        row = trow;
        col = tcol;
        while (row < n and col >= 0)
        {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
};