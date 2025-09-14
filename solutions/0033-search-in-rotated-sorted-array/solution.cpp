class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 1, right = nums.size()-2, n = nums.size();
        if(nums[0] == target)   return 0;
        if(nums[n-1] == target) return n-1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            // cout << mid << " ";
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[left])
            {
                if(target <= nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
                // cout << "I changed in IF" << endl;
            }
            else
            {
                if(target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
                // cout << "I changed in else" << endl;
            }
            // cout << left << " " << right << endl;
        } 
        return -1;   
    }
};
