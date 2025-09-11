class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int left = 0, right = arr.size()-1, n = arr.size();
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(mid - 1 >= 0 && arr[mid - 1] < arr[mid] && mid + 1 < n && arr[mid + 1] < arr[mid])
                return mid;
            else if(mid + 1 < n && arr[mid] < arr[mid+1])
                left = mid + 1;
            else
                right = mid - 1;
        }  
        return -1;  
    }
};
