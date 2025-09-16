class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int max_size = *max_element(nums.begin(), nums.end());
        int left = 1, right = max_size, ans = right;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int ops = 0;
            for(int num : nums)
            {
                ops += (num - 1)/mid;
                if(ops > maxOperations)
                    break;
            }
            if(ops <= maxOperations)
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};
