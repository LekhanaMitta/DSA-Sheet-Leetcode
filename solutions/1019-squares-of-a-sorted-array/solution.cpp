class Solution {
public:
    vector<int> square_array(vector<int> &nums)
    {
        for(int i=0;i<nums.size();i++)
            nums[i] *= nums[i];
        return nums;
    }
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int k = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= 0)
            {
                k = i;
                break;
            }
        }
        if(k == 0)
            return square_array(nums);
        else if(k == -1)
        {
            reverse(nums.begin(), nums.end());
            return square_array(nums);
        }    
        int i = k-1, j = k, l=0;
        vector<int> news(nums.size(),0);
        while(i >= 0 && j < nums.size())
        {
            if(abs(nums[i]) <= nums[j])
                news[l++] = abs(nums[i--]);
            else
                news[l++] = nums[j++];
        }
        while(i >= 0)   news[l++] = abs(nums[i--]);
        while(j < nums.size())  news[l++] = nums[j++];
        // for(int i=0;i<news.size();i++)  cout << news[i] << " ";
        return square_array(news);
    }
};
