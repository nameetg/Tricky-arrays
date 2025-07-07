#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n =  stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int total = (sum + 1) / 2;
        vector<vector<int>> dp(n+1, vector<int>(total + 1, -1));

        function<int(int, int)> dfs = [&] (int idx, int target) -> int {
            if(target >= total || idx == n) return abs(2 * target - sum);

            if(dp[idx][target] != -1) return dp[idx][target];

            return dp[idx][target] = min(dfs(idx + 1, target), dfs(idx + 1, target + stones[idx]));
        };

        return dfs(0, 0);
    }
};