class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> svec;
        if(nums.size() < 4) return {};
        for(int a=0;a<nums.size()-3;a++)
        {
            for(int b=a+1;b<nums.size()-2;b++)
            {
                int c = b+1, d = nums.size()-1;
                while(c < d)
                {
                    long long int sum = nums[a] + nums[b];
                    sum += nums[c] + nums[d];
                    if(sum == target)
                    {
                        svec.insert({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;
                    }
                    else if(sum < target)   c++;
                    else    d--;
                }
            }
        }
        vector<vector<int>> vec;
        for(auto s : svec)
        {
            vec.push_back(s);
        }
        return vec;
    }
};
