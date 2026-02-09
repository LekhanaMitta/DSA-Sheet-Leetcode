// Last updated: 2/9/2026, 1:26:45 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        map<int, bool> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]] = true;
        int flag = true;
        while(flag)
        {
            if(m.find(original) != m.end())
                original = 2 * original;
            else
                flag = false;
        }  
        return original;  
    }
};