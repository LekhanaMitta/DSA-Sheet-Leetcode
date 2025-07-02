class Solution {
public:
    // int climb(int n)
    // {
    //     if(n == 0 || n == 1 || n == 2)
    //         return n;
    //     return climb(n-1) + climb(n-2);
    // }
    int climbStairs(int n) 
    {
        if(n == 1 || n == 2)
            return n;
        int first = 1, second = 2, third = 0;
        for(int i = 3;i<=n;i++)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};
