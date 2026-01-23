## Stock based DP problems
### Leetcode - 121 : Best Time to Buy and Sell Stock
#### DP Approach
##### State :
```cpp
At each day i, you only care about 2 situations:
hold[i] = max profit up to day i if you are holding a stock
cash[i] = max profit up to day i if you are not holding a stock
```
##### Transition :
```
Hold today:
Either you were holding already, or you buy today (only allowed once, from 0 profit):
hold[i] = max(hold[i-1], -p);

Cash today
Either you stay in cash, or you sell today using a previous hold:
cash[i] = max(cash[i-1], hold[i-1] + p);
```
##### Base Case : 
```
hold[0] = -prices[0]  // buy on day 0
cash[0] = 0           // do nothing
```
##### Answer :
```
cash[n-1];
```
