// Last updated: 2/9/2026, 1:26:59 PM
class Solution {
public:
    // int func(vector<int> &arr)
    // {
    //     int l = 0, r = arr.size()-1, n = arr.size();
    //     if(arr[0] < 0)  return n;
    //     if(arr[n-1] >= 0)   return 0;
    //     while(l < r)
    //     {
    //         int m = (l+r)/2;
    //         if(arr[m] >= 0)
    //         {
    //             if(m+1 < n && arr[m+1] < 0)
    //                 return n - m - 1;
    //             else
    //                 l = m+1;
    //         }
    //         else if(arr[m] < 0)
    //         {
    //             if(m-1>=0 && arr[m-1] >= 0)
    //                 return n - m;
    //             else
    //                 r = m - 1;
    //         }
    //     }
    //     return 0;
    // }
    int countNegatives(vector<vector<int>>& grid) 
    {
        // int cnt = 0;
        // for(int i = 0;i<grid.size();i++)
        // {
        //     int out = func(grid[i]);
        //     cout << out << " ";
        //     cnt += out;
        // }
        // return cnt;
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = n-1, cnt = 0;
        while(i < m && j >= 0)
        {
            if(grid[i][j] < 0)
            {
                cnt += (m-i);
                j--;
            }
            else 
                i++;
        }
        return cnt;
    }
};