class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long int ans = 0;
        if(x < 0)   return false;
        long long int x_new = x;
        while(x > 0)
        {
            ans *= 10;
            ans += (x % 10);
            x /= 10;
        }    
        return (x_new == ans);
    }
};
