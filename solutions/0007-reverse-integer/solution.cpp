class Solution {
public:
    int reverse(int x) 
    {
        long long ans = 0;
        bool sign = true;
        if(x == INT_MAX || x == INT_MIN)    return 0;
        if(x < 0)
        {
            sign = false;
            x = 0-x;
        }
        while(x)
        {

            ans *= 10;
            ans += x%10;
            x /= 10;
        }  
        ans = sign ? ans : -ans;
        if (ans > INT_MAX || ans < INT_MIN)
            return 0;
        return (int)ans;
    }
};
