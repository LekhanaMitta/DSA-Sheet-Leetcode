class Solution {
public:
    bool isHappy(int n) 
    {
        while(n > 4)
        {
            int num = 0;
            while(n)
            {
                num += ((n % 10) * (n % 10));
                n = n/10;
            }
            n = num;
        }  
        if(n == 1)  return true;
        return false;  
    }
};
