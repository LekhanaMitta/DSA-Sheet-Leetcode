class Solution {
public:
    int cnt = 0;
    vector<bool> cols, diag1, diag2;
    void backtrack(int r, int n)
    {
        if(r == n)
        {
            cnt++;
            return;
        }
        for(int c =0;c<n;c++)
        {
            int d1 = r - c + (n-1);
            int d2 = r + c;
            if(cols[c] || diag1[d1] || diag2[d2])   continue;

            cols[c] = diag1[d1] = diag2[d2] = 1;
            backtrack(r+1, n);
            cols[c] = diag1[d1] = diag2[d2] = 0;
        }
    }
    int totalNQueens(int n) 
    {
        cols = vector<bool>(n,0);
        diag1 = vector<bool>(2*n-1, 0);
        diag2 = vector<bool>(2*n-1, 0);
        backtrack(0, n);
        return cnt;
    }
};
