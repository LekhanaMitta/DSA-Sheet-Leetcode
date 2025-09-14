class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans = 1.0;
        bool sign = true;
        if(n == -2147483648)
        {
            if(x == 1 || x == -1)  return 1;
            else return 0;
        }
        if(n < 0)
        {
            sign = false;
            n = -n;
        }
        // else if(n == 0)
        //     return 1;
        // else if(n == 1)
        //     return x;
        // while(n > 0)
        // {
        //     if(n % 2 == 1)
        //     {
        //         ans *= x;
        //         n--;
        //     }
        //     else
        //     {
        //         ans *= (x*x);
        //         n -= 2;
        //     }
        // }    
        // return (sign) ? ans : 1/ans;
        while(n)
        {
            if(n % 2 == 1)
                ans *= x;
            x *= x;
            n /= 2;
        }
        return sign ? ans:1/ans;
    }
};
