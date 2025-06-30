class Solution {
public:
    int use_func(vector<int> &nums, int k, int key)
    {
        int j = k-1;
        cout << k << endl;
        for(int i=k;i<nums.size();i++)
        {
            if(nums[i] == key)
            {
                j++;
                swap(nums[i], nums[j]);
                cout << i << " " << j << endl;
            }
        }
        return j+1;
    }
    void sortColors(vector<int>& nums) 
    {
        // int j=-1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i] == 0)
        //     {
        //         j++;
        //         int temp = nums[i];
        //         nums[i] = nums[j];
        //         nums[j] = temp;
        //         // cout << i << " " << j << endl;
        //     }
        // }
        // for(int i=j;i<nums.size();i++)
        // {
        //     if(nums[i] == 1)
        //     {
        //         j++;
        //         int temp = nums[i];
        //         nums[i] = nums[j];
        //         nums[j] = temp;
        //     }
        // }
        int k = 0;
        k = use_func(nums, k, 0);
        k = use_func(nums, k, 1);
    }
};
