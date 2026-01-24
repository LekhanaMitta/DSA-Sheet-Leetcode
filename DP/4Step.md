# Stock based DP problems
## Leetcode - 121 : Best Time to Buy and Sell Stock
### DP Approach - 1:
#### State :
```
At each day i, you only care about 2 situations:
hold[i] = max profit up to day i if you are holding a stock
cash[i] = max profit up to day i if you are not holding a stock
```
#### Transition :
```
Hold today:
Either you were holding already, or you buy today (only allowed once, from 0 profit):
hold[i] = max(hold[i-1], -p);

Cash today
Either you stay in cash, or you sell today using a previous hold:
cash[i] = max(cash[i-1], hold[i-1] + p);
```
#### Base Case : 
```
hold[0] = -prices[0]  // buy on day 0
cash[0] = 0           // do nothing
```
#### Answer :
```
cash[n-1];
```
### DP Approach - 2:
#### State :
```
At each day i, you only care about 2 situations:
buy[i] = min price of stock you can buy on ith day
profit[i] = max profit of stock you can get from selling a stock on the ith day
```
#### Transition :
```
Buy today:
Either you bought already, or you buy today (only allowed once, from 0 profit):
buy[i] = min(buy[i-1], p);

Profit today
Either you stay in profit, or you sell today using a previous buy:
profit[i] = max(profit[i-1], p - buy[i]);
```
#### Base Case : 
```
buy[0] = prices[0]  // buy on day 0
profit[0] = 0           // do nothing
```
#### Answer :
```
profit[n-1];
```

### Final Code : 
```cpp
    int maxProfit(vector<int>& prices) 
    {
        int buy = prices[0], sell = 0;
        for(int i=1;i<prices.size();i++)
        {
            sell = max(sell, prices[i]-buy);
            buy = min(prices[i], buy);
        }  
        return sell;  
    }
```

## Leetcode - 122 : Best Time to Buy and Sell Stock II (Unlimited Transactions)
### DP Approach - 1 (Hold/Cash DP)
#### State :

```
At each day i, you only care about 2 situations:
hold[i] = max profit up to day i if you are holding a stock
cash[i] = max profit up to day i if you are not holding a stock
```

#### Transition :

Let p = prices[i]

```
Hold today:
Either you were holding already, or you buy today (you must come from cash):
hold[i] = max(hold[i-1], cash[i-1] - p);

Cash today:
Either you stay in cash, or you sell today using a previous hold:
cash[i] = max(cash[i-1], hold[i-1] + p);
```

#### Base Case :

```
hold[0] = -prices[0]  // buy on day 0
cash[0] = 0           // do nothing
```

#### Answer :

```
cash[n-1];
```

---

### DP Approach - 2 (Min buy / Max profit via "sum of rises" — Greedy equivalent)

> For Stock II, doing unlimited transactions means you can take profit from every upward move.
> This is equivalent to repeatedly choosing local min buy and local max sell.

#### State :

```
At each day i:
profit = total profit collected so far
(Think of each rising segment as one mini transaction)
```

#### Transition :

```
If price goes up from yesterday to today, take that profit:
if (prices[i] > prices[i-1])
    profit += prices[i] - prices[i-1];
```

#### Base Case :

```
profit = 0
```

#### Answer :

```
profit
```

---

### Final Code (DP Hold/Cash, O(1) space) :

```cpp
int maxProfit(vector<int>& prices) 
{
    int hold = -prices[0], cash = 0;

    for(int i = 1; i < prices.size(); i++)
    {
        int p = prices[i];
        int prevHold = hold, prevCash = cash;

        hold = max(prevHold, prevCash - p);
        cash = max(prevCash, prevHold + p);
    }
    return cash;
}
```

---

### Final Code (Sum of rises, simplest for Stock II) :

```cpp
int maxProfit(vector<int>& prices) 
{
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    }
    return profit;
}
```

## Leetcoce 123 - Best Time to Buy and Sell Stock III
### DP Approach - 1:
#### State :
```
We need to know:
how many transactions (sells) we’ve completed: 0, 1, 2 whether we are holding a stock or in cash
Use 4 states (optimized form):
hold1 = max profit after 1st buy (holding)
cash1 = max profit after 1st sell (cash)
hold2 = max profit after 2nd buy (holding)
cash2 = max profit after 2nd sell (cash)
```
#### Transition :
```
hold1 = max(hold1, -p)
cash1 = max(cash1, hold1 + p)

hold2 = max(hold2, cash1 - p)
cash2 = max(cash2, hold2 + p)
```
#### Base Case :
```
hold1 = -prices[0]
cash1 = 0
hold2 = -prices[0]
cash2 = 0
```
#### Answer :
```
answer = cash2
```
#### Code :
```cpp
int maxProfit(vector<int>& prices) {
    int hold1 = -prices[0], cash1 = 0;
    int hold2 = -prices[0], cash2 = 0;

    for (int i = 1; i < prices.size(); i++) {
        int p = prices[i];
        hold1 = max(hold1, -p);
        cash1 = max(cash1, hold1 + p);
        hold2 = max(hold2, cash1 - p);
        cash2 = max(cash2, hold2 + p);
    }
    return cash2;
}
```

### DP Approach - 2 :
#### State :
```
buy1 = minimum price to buy first stock
sell1 = max profit after first sell

buy2 = minimum effective price to buy second stock
(effective because you can reuse profit from first transaction)
sell2 = max profit after second sell
```
#### Transition :
```
buy1  = min(buy1, p)
sell1 = max(sell1, p - buy1)

buy2  = min(buy2, p - sell1)
sell2 = max(sell2, p - buy2)
```
#### Base Case :
```
buy1 = prices[0], sell1 = 0
buy2 = prices[0], sell2 = 0
```
#### Answer :
```
answer = sell2
```
#### Code :
```cpp
int maxProfit(vector<int>& prices) {
    int buy1 = prices[0], sell1 = 0;
    int buy2 = prices[0], sell2 = 0;

    for (int i = 1; i < prices.size(); i++) {
        int p = prices[i];

        buy1  = min(buy1, p);
        sell1 = max(sell1, p - buy1);

        buy2  = min(buy2, p - sell1);
        sell2 = max(sell2, p - buy2);
    }
    return sell2;
}
```
