class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 0 || x == 1)    return x;
        // long long i = 1;
        // while(i++ && i*i <= x)
        // {
        //     if(i*i == x)    return i;
        // }
        // return --i;
        int l = 0, r = x, ans = 0;
        while(l <= r)
        {
            int m = (l+r)/2;
            ans = x/m;
            if(ans == m) return m;
            else if(ans < m) r = m-1;
            else 
            {
                ans = m;
                l=m+1;
            }  
        }
        return ans;

    }
};
