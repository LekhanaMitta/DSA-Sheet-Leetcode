class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        /* 
        1. Hold : either hold today or buy a stock on ith day(if buying come from cool down)
        hold[i] = max(hold[i-1], cool[i-1]-p)
        2. Cool : either sold yesterday or staying in cooldown on ith day
        cool[i] = max(cool[i-1], cash[i-1])
        3. Cash : selling on ith day
        cash[i] = hold[i-1]+p
        */
        int n = prices.size();
        int buy = INT_MIN, cool = 0, profit = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int prev_buy = buy, prev_profit = profit, prev_cool = cool;
            buy = max(prev_buy, prev_cool - prices[i]);
            profit = prev_buy + prices[i];
            cool = max(prev_cool, prev_profit);
            // Below one works well but we need to use the previous values to update today's
            // buy = max(buy, cool - prices[i]);
            // cool = max(cool, profit);
            // profit = buy + prices[i];
        }
        return max(cool, profit);
    }
};
