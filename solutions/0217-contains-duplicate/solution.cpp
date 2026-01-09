class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // map<int, int> m;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(m.find(nums[i])!=m.end()) return true;
        //     m[nums[i]] = i;
        // }  
        // return false;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i] == nums[i+1])    return true;
        // }
        // return false;
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        int m = s.size();
        return (n == m) ? false : true;
    }
};
