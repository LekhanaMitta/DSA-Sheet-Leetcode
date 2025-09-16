class Solution {
public:
    bool search_row(vector<int> &vec, int target)
    {
        int left = 0, right = vec.size()-1, n = vec.size();
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(vec[mid] == target)  return true;
            else if(vec[mid] > target)  right = mid - 1;
            else    left = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int top = 0, bottom = matrix.size()-1, m = matrix.size();
        int left = 0, right = matrix[0].size()-1, n = matrix[0].size();    
        while(top <= bottom)
        {
            int mid_col = (top + bottom)/2;
            if(matrix[mid_col][0] <= target && matrix[mid_col][n-1] >= target)
                return search_row(matrix[mid_col], target);
            else if(matrix[mid_col][0] > target)
                bottom = mid_col - 1;
            else 
                top = mid_col + 1;
        }
        return false;
    }
};
