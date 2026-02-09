// Last updated: 2/9/2026, 1:28:02 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        int cnt = 0;
        for(int i=1;i<nums.size();i++)  prefix[i] = prefix[i-1] + nums[i];
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         int sum = prefix[j] - prefix[i] + nums[i];
        //         if(sum == k)
        //             cnt++;
        //     }
        // }
        map<int, int> m;
        for(int i = 0;i<nums.size();i++)
        {
            if(prefix[i] == k)  cnt++;
            if(m.find(prefix[i]-k) != m.end())
                cnt += m[prefix[i]-k];
            m[prefix[i]]++;
        }
        return cnt;
    }
};