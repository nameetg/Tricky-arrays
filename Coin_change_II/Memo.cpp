#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1,vector<int>(amount + 1, -1));
        function<int(int,int)> dfs = [&](int idx, int target) -> int {
            if(!target) return 1;
            if(idx >= n) return 0;
            if(dp[idx][target] != -1) return dp[idx][target];

            int take = 0, notTake = 0;
            notTake = dfs(idx + 1, target);
            if(target >= coins[idx]) take = dfs(idx, target - coins[idx]);

            return dp[idx][target] = take + notTake;
        };

        return dfs(0, amount);
    }
};