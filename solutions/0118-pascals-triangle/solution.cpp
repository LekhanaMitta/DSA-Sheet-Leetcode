class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        if(numRows == 1)    return pascal;
        pascal.push_back({1,1});
        if(numRows == 2)    return pascal;
        // cout << pascal[0][0] << " " << pascal[1][0] << " " << pascal[1][1];
        for(int i=2;i<numRows;i++)
        {
            vector<int> temp(i+1, 0);
            // cout << numRows << endl;
            for(int j=0;j<=i;j++)
            {
                // cout << i << " " << j << " ";
                if(j == 0 || j == i)
                    temp[j] = 1;
                else
                    temp[j] = pascal[i-1][j-1] + pascal[i-1][j];
                // cout << temp[j] << endl;
            }
            pascal.push_back(temp);
        }  
        return pascal;
    }
};
