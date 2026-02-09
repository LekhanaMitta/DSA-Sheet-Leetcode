// Last updated: 2/9/2026, 1:27:41 PM
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        int a = intervals[0][1]-1;
        int b = intervals[0][1];
        int ans = 2;
        for(int i=1;i<intervals.size();i++)
        {
            /*
            case - 1 : Both points lie in the interval.
            case - 2 : None of the points lie in the interval.
            case - 3 : Only one point lie in the interval.
            */
            // case - 1
            if(a >= intervals[i][0])
            {
                continue;
            }
            // case - 2:
            else if(b < intervals[i][0])
            {
                ans += 2;
                a = intervals[i][1] - 1;
                b = intervals[i][1];
            }
            // case - 3;
            else
            {
                ans += 1;
                a = b;
                b = intervals[i][1];
            }
        }
        return ans;
    }
};