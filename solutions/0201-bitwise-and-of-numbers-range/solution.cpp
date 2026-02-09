class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        // if(left == 0 || right == 0) return 0;
        // int x = log2(left), y = log2(right);   
        // if(x != y)  return 0;
        // int ans = left;
        // for(long long i=left;i<=right;i++)
        //     ans &= i;
        // return ans;
        int cnt = 0;
        while(left != right)
        {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left<<cnt);
    }
};
