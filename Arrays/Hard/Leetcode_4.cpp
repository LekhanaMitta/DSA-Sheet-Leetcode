class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size();
        int newSize = (m + n + 1)/2;
        int left = 0, right = m;
        while(left <= right)
        {
            int midA = (left + right)/2;
            int midB = newSize - midA;
            int leftA = (midA > 0) ? nums1[midA - 1] : INT_MIN;
            int rightA = (midA < m) ? nums1[midA] : INT_MAX;
            int leftB = (midB > 0) ? nums2[midB - 1] : INT_MIN;
            int rightB = (midB < n) ? nums2[midB] : INT_MAX;
            if(leftA > rightB)  right = midA - 1;
            else if(leftB > rightA)  left = midA + 1;
            else
            {
                if((m+n) % 2 == 1)
                    return (double) max(leftA, leftB);
                else
                    return (double)(max(leftA, leftB) + min(rightA, rightB))/2.0;
            }
        }
        return 0.0;
    }
};
