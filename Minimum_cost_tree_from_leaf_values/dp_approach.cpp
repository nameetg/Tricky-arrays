#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> maxVal(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            maxVal[i][i] = arr[i];
            for(int j = i + 1; j < n; j++) maxVal[i][j] = max(maxVal[i][j-1], arr[j]);
        }

        function<int(int ,int)> dfs = [&] (int i, int j) -> int {
            if(i == j) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            int res = INT_MAX;
            for(int idx = i; idx < j; idx++){
                int left = dfs(i, idx);
                int right = dfs(idx + 1, j);
                int cost = left + right + maxVal[i][idx] * maxVal[idx+1][j];
                res = min(res, cost);
            }

            return dp[i][j] = res;
        };

        return dfs(0, n-1);
    }
};