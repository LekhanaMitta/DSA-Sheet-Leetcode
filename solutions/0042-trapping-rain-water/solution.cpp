class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<vector<int>> v(n, vector<int>(2,0));
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            if(mx <= height[i])  mx = height[i];
            v[i][1] = mx;
        }
        mx = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(mx <= height[i]) mx = height[i];
            v[i][0] = mx;
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int mn = min(v[i][0], v[i][1]);
            if(mn > height[i])  cnt += (mn - height[i]);
        }
        return cnt;

    }
};
/*
0 1 0 2 1 0 1 3 2 1 2 1 - Input
1 2 2 3 3 3 3 3 2 2 0 0 - next greater from left to right
0 1 1 2 2 2 2 3 3 3 3 2 - next greater from right to left
0 0 1 0 1 2 1 0 0 1 0 0 - min(a, b) - curr. if val < 0 , return 0

4 2 0 3 2 5
5 5 5 5 5 5
4 4 4 4 4 0
0 2 4 1 2 0
*/
