class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> vec;
        set<vector<int>> svec;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i])
            int j = i+1, k = nums.size()-1;
            while(j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0)
                {
                    svec.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0)
                    j++;
                else
                    k--;
            }   
        } 
        for(auto it:svec)
            vec.push_back(it);
        return vec;   
    }
};
