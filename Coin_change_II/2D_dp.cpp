#include<bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<i64>> dp(n + 1, vector<i64>(amount + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                i64 notTake = dp[i + 1][j];
                i64 take = 0;
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }

        return (int)dp[0][amount];
    }
};
