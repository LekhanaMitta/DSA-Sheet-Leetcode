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
## Leetcode - 97 : Interleaving Strings
### DP Approach :
#### State :
```
dp[i][j] = true if s3[0..i+j-1] can be formed
           using s1[0..i-1] and s2[0..j-1]
```
#### Transition :
```
Let k = i + j - 1 (index in s3 we are trying to match last).
We can reach dp[i][j] in 2 ways:

Option A: last char came from s1
If i > 0 and s1[i-1] == s3[k], then:
dp[i][j] |= dp[i-1][j]

Option B: last char came from s2
If j > 0 and s2[j-1] == s3[k], then:
dp[i][j] |= dp[i][j-1]

So overall:
dp[i][j] =
   (i>0 && dp[i-1][j] && s1[i-1]==s3[i+j-1])
|| (j>0 && dp[i][j-1] && s2[j-1]==s3[i+j-1])
```
#### Base Case :
```
dp[0][0] = true

First row (only using s2):
dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1])

First column (only using s1):
dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1])
```
#### Answer :
```
dp[n][m]
```
#### Code : 
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != (int)s3.size()) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int k = i + j - 1;
                if (i > 0 && s1[i - 1] == s3[k]) dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j > 0 && s2[j - 1] == s3[k]) dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
```
## Leetcode - 115 : Distinct SubSequences
### [DP Approach](https://github.com/LekhanaMitta/DSA-Sheet-Leetcode/blob/main/DP/Hard/Leetcode_115.cpp) :
#### State :
```
dp[i][j] = number of ways to form t[0..j-1] using s[0..i-1]
```
#### Transition :
```
Look at the last characters: s[i-1] and t[j-1].
If they match there are 2 choices:
i. Skip s[i-1] -> dp[i-1][j]
ii. Use s[i-1] to match t[j-1] -> dp[i-1][j-1]
So:
dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

If they don’t match you can only skip s[i-1]:
dp[i][j] = dp[i-1][j]
```
#### Base Case :
```
dp[i][0] = 1   for all i     // empty t can be formed in exactly 1 way
dp[0][j] = 0   for j > 0     // non-empty t can't be formed from empty s
```
#### Answer :
```
dp[n][m]
```
#### Code : 
```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int)dp[m];
    }
};
```
# DP on Increasing SubSequence or Path : 
## Leetcode - 300 : Longest Increasing Subsequence (Need to be Optimized)
### DP Approach :
#### State :
```
dp[i] = length of the longest increasing subsequence ending at index i
```
#### Transition :
```
To compute dp[i], look at all previous indices j < i.
If nums[j] < nums[i], then nums[i] can extend the subsequence ending at j:
dp[i] = max(dp[i], dp[j] + 1)   for all j < i where nums[j] < nums[i]
```
#### Base Case :
```
dp[i] = 1   for all i
```
#### Answer :
```
answer = max(dp[i]) over all i
```
#### Code : 
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
## Leetcode - 329 : Longest Increasing Path in a Matrix
### DP Approach :
#### State :
```
dp[i][j] = length of the longest strictly increasing path
           starting from cell (i, j)
```
#### Transition :
```
From (i, j), you can go to any neighbor (x, y) where:
matrix[x][y] > matrix[i][j]
So:
dp[i][j] = 1 + max(dp[x][y]) over all valid increasing neighbors

If there are no valid neighbors:
dp[i][j] = 1
```
#### Base Case :
```
dp[i][j] = 1
```
#### Answer :
```
answer = max(dp[i][j]) over all cells
```
#### Code : 
```cpp
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>>& a, int r, int c) {
        if (dp[r][c] != 0) return dp[r][c];

        int best = 1;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && a[nr][nc] > a[r][c]) {
                best = max(best, 1 + dfs(a, nr, nc));
            }
        }
        return dp[r][c] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};
```
## Leetcode - 2328 : Number of Increasing Paths in a Grid
### DP Approach :
#### State :
```
dp[i][j] = number of strictly increasing paths starting from cell (i, j)
```
#### Transition :
```
From (i,j), you can go to any neighbor (x,y) with a bigger value:
grid[x][y] > grid[i][j]
So:
dp[i][j] = 1 + sum(dp[x][y]) over all increasing neighbors (x,y)

Why sum (not max):
We are counting all different paths.
Each valid next step contributes additional paths.
```
#### Base Case :
```
dp[i][j] = 1
```
#### Answer :
```
answer = sum(dp[i][j]) over all cells  (mod M)
```
#### Code : 
```cpp
class Solution {
public:
    static const int MOD = 1000000007;
    int m, n;
    vector<vector<int>> dp;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (dp[r][c] != -1) return dp[r][c];

        long long ways = 1; // path of length 1: just this cell
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[r][c]) {
                ways += dfs(grid, nr, nc);
                ways %= MOD;
            }
        }
        return dp[r][c] = (int)ways;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += dfs(grid, i, j);
                ans %= MOD;
            }
        }
        return (int)ans;
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
