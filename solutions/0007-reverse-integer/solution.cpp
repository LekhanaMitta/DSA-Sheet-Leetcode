class Solution {
public:
// 2147483648
    int reverse(int x) 
    {
        bool sign = (x < 0) ? false:true;
        if(x == -2147483648)    return 0;
        x = (x < 0) ? -x:x;
        long long int ans = 0;
        while(x > 0)
        {
            ans *= 10;
            ans += x%10;
            x /= 10;
        }  
        if(sign && ans > 2147483647)    return 0;
        if(!sign && ans > 2147483648)   return 0;
        return sign ? ans:0-ans;  
    }
};
