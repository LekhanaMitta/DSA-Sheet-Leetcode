class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int cnt = 1, max_elem = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == max_elem)
                cnt++;
            else
                cnt--;
            if(cnt == 0)
            {
                max_elem = nums[i];
                cnt = 1;
            }
        }    
        return max_elem;
    }
};
