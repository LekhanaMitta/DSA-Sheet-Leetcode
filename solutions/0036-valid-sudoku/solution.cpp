class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // check if sudoku is valid in rows
        for(int i=0;i<9;i++)
        {
            vector<bool>checker(9, false);
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(checker[board[i][j]-'0'])
                        return false;
                    else
                        checker[board[i][j]-'0'] = true;
                }
            }
        }  
        // check if sudoku is valid in columns
        for(int i=0;i<9;i++)
        {
            vector<bool>checker(9, false);
            for(int j=0;j<9;j++)
            {
                if(board[j][i] != '.')
                {
                    if(checker[board[j][i]-'0'])
                        return false;
                    else
                        checker[board[j][i]-'0'] = true;
                }
            }
        } 
        // check if sudoku is valid in sub-boxes 
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                vector<bool> checker(9, false);
                for(int l=i;l<i+3;l++)
                {
                    for(int m=j;m<j+3;m++)
                    {
                        if(board[l][m] != '.')
                        {
                            if(checker[board[l][m]-'0'])
                                return false;
                            else
                                checker[board[l][m]-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
