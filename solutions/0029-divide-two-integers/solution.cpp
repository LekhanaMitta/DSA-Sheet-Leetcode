class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long cnt = -1;
        if(dividend == INT_MIN && divisor == -1)    return INT_MAX;
        if(dividend == INT_MAX && divisor == -1) return INT_MIN + 1;
        long long int add = 0;
        if(dividend == 0)   return 0;
        bool sign = true;
        if(dividend < 0 ^ divisor < 0)
            sign = false;
        long long divid = dividend;
        divid = (divid < 0) ? -divid : divid;
        long long divis = divisor;
        divis = (divis < 0) ? -divis: divis;
        while(add <= divid)
        {
            add += divis;
            cnt++;
        } 
        return sign ? cnt: -cnt;
    }
};
