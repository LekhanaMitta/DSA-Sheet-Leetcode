class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX, ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int j =i+1, k=nums.size()-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << sum << endl;
                if(sum == target)   return target;
                else if(sum < target)
                    j++;
                else
                    k--;
                if(abs(sum - target) < mn)
                {
                    ans = sum;
                    mn = min(abs(sum-target),mn);
                }
            }
        } 
        return ans; 
    }
};
