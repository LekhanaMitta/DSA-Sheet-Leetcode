class Solution {
public:
    void backtrack(vector<vector<string>> &res, vector<string> &board, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2, int r, int n)
    {
        if(r == n)
        {
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++)
        {
            int d1 = r-c+(n-1);
            int d2 = r+c;
            if(cols[c] || diag1[d1] || diag2[d2])   continue;

            board[r][c] = 'Q';
            cols[c] = diag1[d1] = diag2[d2] = 1;

            backtrack(res, board, cols, diag1, diag2, r+1, n);

            board[r][c] = '.';
            cols[c] = diag1[d1] = diag2[d2] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board = vector<string>(n,string(n,'.'));
        vector<bool> cols(n,0);
        vector<bool> diag1(2*n-1,0);
        vector<bool> diag2(2*n-1,0);

        backtrack(res, board, cols, diag1, diag2, 0, n);
        return res;
    }
};
