class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = prices[0], profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(buy < prices[i])
                profit += (prices[i] - buy);
            buy = prices[i];
        }    
        return profit;
    }
};
