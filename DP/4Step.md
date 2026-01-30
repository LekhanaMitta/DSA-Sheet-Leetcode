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

## Leetcode - 188 : Best Time to Buy and Sell Stock IV
### DP Approach - 1 : 
#### State :
```
For each transaction number t from 1..k:
buy[t] = minimum effective buy cost for the t-th transaction
sell[t] = maximum profit after t sells (t completed transactions)
```
#### Transition :
```
buy[t]  = min(buy[t],  p - sell[t-1]);
sell[t] = max(sell[t], p - buy[t]);
```
#### Base Case :
```
sell[0] = 0
sell[t] = 0 for all t (no profit if you never sell)
buy[t]  = +infinity (start with very large so min() works)
```
#### Answer :
```
answer = sell[k]
```
#### Code : 
```cpp
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        if(k>=n/2)
        {
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i-1]) 
                    profit += prices[i] - prices[i-1];
            return profit;
        }
        vector<int> buy(k+1, INT_MAX/2);
        vector<int> profit(k+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                buy[j] = min(buy[j],prices[i]-profit[j-1]);
                profit[j] = max(profit[j],prices[i]-buy[j]);
            }
        }
        return profit[k];
    }
```
## Leetcode - 309 : Best Time to Buy and Sell Stock With Cooldown
### DP Approach :
#### State : 
```
hold[i] = max profit up to day i if you are holding a stock
sold[i] = max profit up to day i if you sold a stock today (day i)
rest[i] = max profit up to day i if you are not holding and not selling today
         (i.e., you are free to buy)
```
#### Transition :
```
Hold today
Either keep holding, or buy today (you can only buy from rest, not from sold)
hold[i] = max(hold[i-1], rest[i-1] - p)
Sold today
To sell today, you must have been holding yesterday
sold[i] = hold[i-1] + p
Either keep resting, or come from yesterday’s sold (cooldown day passes)
rest[i] = max(rest[i-1], sold[i-1])
```
#### Base Case :
```
hold[0] = -prices[0]     // buy on day 0
sold[0] = -∞             // impossible to sell on day 0
rest[0] = 0              // do nothing
```
#### Answer :
```
answer = max(sold[n-1], rest[n-1])
```
#### Code :
```cpp
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
```
# DP on Coin Change : 
## Leetcode - 322 : Coin Change 
### DP Approach :
#### State : 
```
dp[x] = minimum number of coins needed to make amount x
```
#### Transition :
```
dp[x] = min(dp[x - coin] + 1)   for all coins where x - coin >= 0
```
#### Base Case :
```
dp[0] = 0     // 0 coins to make amount 0
dp[x] = ∞     // initially assume impossible
```
#### Answer :
```
if dp[amount] == ∞ → return -1
else return dp[amount]
```
#### Code :
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;

        for (int x = 1; x <= amount; x++) {
            for (int coin : coins) {
                if (x - coin >= 0) {
                    dp[x] = min(dp[x], dp[x - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
```
## Leetcode 518 : Coin Change II
### DP Approach :
#### State : 
```
dp[x] = number of combinations to make amount x
```
#### Transition :
```
dp[x] += dp[x - c]
```
#### Base Case :
```
dp[0] = 1
```
#### Answer :
```
dp[amount]
```
#### Code :
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins) {
            for (int x = c; x <= amount; x++) {
                dp[x] += dp[x - c];
            }
        }
        return (int)dp[amount];
    }
};
```
## Leetcode 983 : Minimum Cost for Tickets 
### DP Approach :
#### State : 
```
dp[i] = minimum cost to cover travel days from index i to the end
```
#### Transition :
```
dp[i] = min(
    cost1  + dp[next index not covered by 1-day pass],
    cost7  + dp[next index not covered by 7-day pass],
    cost30 + dp[next index not covered by 30-day pass]
)
```
#### Base Case :
```
dp[n] = 0
```
#### Answer :
```
dp[0]
```
#### Code :
```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days[days.size()-1];
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--)
        {
            dp[i] = min(dp[i+1]+costs[0], min(dp[min(n,i+7)]+costs[1], dp[min(n,i+30)]+costs[2]));
        }    
        return dp[days[0]];
    }
};
```
## Leetcode 416 : Partition Equal Subset Sum
### DP Approach :
#### State : 
```
dp[t] = true/false
= can we form sum t using some of the numbers processed so far?
```
#### Transition :
```
for t from target down to num:
    dp[t] = dp[t] OR dp[t - num]
```
#### Base Case :
```
dp[0] = true
dp[others] = false
```
#### Answer :
```
dp[target]
```
#### Code :
```cpp
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 == 1)    return 0;
        int t = sum/2;
        vector<bool> dp(t+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++)
        {
            for(int j=t;j>=nums[i];j--)
            {
                dp[j] = dp[j-nums[i]] || dp[j];
            }
        }    
        return dp[t];
    }
```
# Fibonacci Based DP Problems:
## Leetcode - 70 : Climbing Stairs
### DP Approach :
#### State :
```
dp[i] = number of distinct ways to reach step i
```
#### Transition :
```
To reach step i, your last move must be:
from step i-1 (1 step jump), or
from step i-2 (2 step jump)
dp[i] = dp[i-1] + dp[i-2]
```
#### Base Case :
```
dp[0] = 1   // one way to stay at ground (do nothing)
dp[1] = 1   // one way: 1 step
```
#### Answer :
```
dp[n]
```
#### Code : 
```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```
Can be further space optimized using just two variables, and updating them for every iteration.
```cpp
int climbStairs(int n) {
    int prev2 = 1, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```
## Leetcode - 746 : Minimum Cost Climbing Stairs
### DP Approach :
#### State :
```
dp[i] = minimum cost to reach step i
```
#### Transition :
```
To reach step i, you must come from:
step i-1 or step i-2
dp[i] = min(
    dp[i-1] + cost[i-1],
    dp[i-2] + cost[i-2]
)
```
#### Base Case :
```
dp[0] = 0
dp[1] = 0
```
#### Answer :
```
dp[n]
```
#### Code : 
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};
```
Further it can be space optimized :
```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev2 = 0, prev1 = 0;

    for (int i = 2; i <= n; i++) {
        int cur = min(prev1 + cost[i - 1],
                      prev2 + cost[i - 2]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```
## Leetcode - 198 : House Robber
### DP Approach :
#### State :
```
dp[i] = maximum money you can rob from houses 0..i
```
#### Transition :
```
For house i, you have 2 choices:
Skip house i -> take best till i-1
Rob house i -> add nums[i] + best till i-2
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
```
#### Base Case :
```
dp[0] = nums[0]
dp[1] = max(nums[0], nums[1])
```
#### Answer :
```
dp[n-1]
```
#### Code : 
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = nums[0];                  // dp[i-2]
        int prev1 = max(nums[0], nums[1]);    // dp[i-1]

        for (int i = 2; i < n; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
```
## Leetcode - 213 : House Robber II
### DP Approach :
#### State :
```
dp[i] = max money you can rob from houses l..i
```
#### Transition :
```
For each house i in the chosen range:
Skip it: keep previous best
Rob it: add its value + best from two steps back
cur = max(prev1, prev2 + nums[i])
```
#### Base Case :
```
So split into two cases:
Rob from 0 .. n-2 (exclude last)
Rob from 1 .. n-1 (exclude first)

Base handling:
If n == 1 -> answer is nums[0]
```
#### Answer :
```
answer = max( robLinear(0, n-2), robLinear(1, n-1) )
```
#### Code : 
```cpp
class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = l; i <= r; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(robLinear(nums, 0, n - 2),
                   robLinear(nums, 1, n - 1));
    }
};
```
# DP on Strings : 
## Leetcode - 1143 : Longest Common SubSequence
### DP Approach :
#### State :
```
dp[i][j] = length of the LCS between
           s[0..i-1] and t[0..j-1]
```
#### Transition :
```
Look at the last characters:
s[i-1] & t[j-1]
if s[i-1] == t[j-1]
dp[i][j] = 1 + dp[i-1][j-1]
else if s[i-1] != t[j-1]
We have two choices:
Skip s[i-1]
Skip t[j-1]
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```
#### Base Case :
```
dp[i][0] = 0   for all i
dp[0][j] = 0   for all j
```
#### Answer :
```
dp[n][m]
```
#### Code : 
```cpp
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
```
## Leetcode - : Longest Common SubString
### DP Approach :
#### State :
```
dp[i][j] = length of the longest common substring
           ending at s[i-1] and t[j-1]
```
#### Transition :
```
If s[i-1] == t[j-1]:
dp[i][j] = 1 + dp[i-1][j-1]
else
dp[i][j] = 0
```
#### Base Case :
```
dp[0][*] = 0
dp[*][0] = 0
```
#### Answer :
```
answer = max(dp[i][j]) over all i, j
```
#### Code : 
```cpp
class Solution {
public:
    int longestCommonSubstring(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

```
## Leetcode - 647 : Palindromic SubString
### DP Approach :
#### State :
```
dp[i][j] = true if substring s[i..j] is a palindrome
```
#### Transition :
```
A string is a palindrome if:
the end characters match and the inside is also a palindrome
dp[i][j] = (s[i] == s[j]) AND (j - i <= 2 OR dp[i+1][j-1])
```
#### Base Case :
```
dp[i][i] = true        // single character
dp[i][i+1] = (s[i] == s[i+1])
```
#### Answer :
```
```
#### Code : 
```cpp
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) dp[i][i] = true;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || dp[i+1][j-1])) {
                dp[i][j] = true;
                if (len > maxLen) {
                    maxLen = len;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}
```
## Leetcode - 516 : Longest Palindromic SubSequence
### DP Approach :
#### State :
```dp[i][j] = length of longest palindromic subsequence in s[i..j]
```
#### Transition :
```
If characters match:
dp[i][j] = 2 + dp[i+1][j-1]

If characters don’t match:
dp[i][j] = max(dp[i+1][j], dp[i][j-1])

Why this works:
Matching ends -> they must be part of palindrome
Otherwise -> skip one end and try best option
```
#### Base Case :
```
dp[i][i] = 1   // single character palindrome
```
#### Answer :
```
dp[0][n-1]
```
#### Code : 
```cpp
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
```
## Leetcode - 5 : Longest Palindromic SubString 
### DP Approach :
#### State :
```
dp[i][j] = true if s[i..j] is a palindrome
```
#### Transition :
```
A substring s[i..j] is palindrome if:
outer chars match: s[i] == s[j] and inside is palindrome (or length is small):
dp[i][j] = (s[i] == s[j]) AND (j - i <= 2 OR dp[i+1][j-1])
```
#### Base Case :
```
dp[i][i] = true
dp[i][i+1] = (s[i] == s[i+1])
```
#### Answer :
```
```
#### Code : 
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) dp[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
```
## Leetcode - :
### DP Approach :
#### State :
```
```
#### Transition :
```
```
#### Base Case :
```
```
#### Answer :
```
```
#### Code : 
```cpp
```
## Leetcode - :
### DP Approach :
#### State :
```
```
#### Transition :
```
```
#### Base Case :
```
```
#### Answer :
```
```
#### Code : 
```cpp
```
