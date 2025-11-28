#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // minPrefix[r] = minimum prefix sum seen so far at prefix indices i
        // such that i % k == r (here i is the length of prefix)
        vector<long long> minPrefix(k, (long long)4e18);

        long long prefixSum = 0;
        long long ans = LLONG_MIN;

        // Prefix index i = 0 (empty prefix, length 0)
        // 0 % k == 0, so base case:
        minPrefix[0] = 0;

        // i is prefix length from 1..n, nums index = i-1
        for (int i = 1; i <= n; ++i) {
            prefixSum += nums[i - 1];
            int r = i % k;

            // Try to form a subarray ending at i-1 with length divisible by k
            ans = max(ans, prefixSum - minPrefix[r]);

            // Update minimum prefix sum for this remainder class
            if (prefixSum < minPrefix[r])
                minPrefix[r] = prefixSum;
        }

        return ans;  // DO NOT cast to int; answer can be up to ~2e14
    }
};

