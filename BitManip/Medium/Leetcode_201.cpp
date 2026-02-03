class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        int cnt = 0;

        // Keep shifting both numbers right until they become equal
        // This removes differing least-significant bits
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            cnt++;   // Count how many shifts we did
        }

        // Shift the common prefix back to its original position
        return left << cnt;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        // If either number is 0, AND will definitely be 0
        // because 0 & anything = 0
        if (left == 0 || right == 0) return 0;

        // Find the position of the highest set bit in left and right
        // log2 gives the index of the most significant bit
        int x = log2(left);
        int y = log2(right);

        // If left and right have different MSB positions,
        // then at some point the MSB will flip to 0,
        // making the AND result 0
        if (x != y) return 0;

        // Otherwise, brute-force AND all numbers in the range
        int ans = left;
        for (long long i = left; i <= right; i++)
            ans &= i;

        return ans;
    }
};
