#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins){
            for(int j = coin; j <= amount; j++) dp[j] += dp[j - coin];
        }

        return dp[amount];
    }
};