class Solution {
public:
    int Can(vector<int>& weights, int capacity, int days)
    {
        int day = 1;
        int load = 0;
        for(int weigh : weights)
        {
            if(weigh + load > capacity)
            {
                day++;
                load = 0;
            }
            load += weigh;
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int max_weight = *max_element(weights.begin(), weights.end());
        int sum_weight = accumulate(weights.begin(), weights.end(), 0);
        int left = max_weight, right = sum_weight, ans = right;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(Can(weights, mid, days))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};
