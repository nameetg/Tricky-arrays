#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,int> freq;
        map<int,int> dp;
        int M = 1e9 + 7;

        for(int e: arr) freq[e]++;

        function<long long(int)> dfs = [&](int root) -> long long {
            if(dp.count(root)) return dp[root];

            long long res = 1;
            
            for(int left : arr){
                if(left >= root) continue;

                if(root % left != 0) continue;

                int right = root / left;

                if(!freq.count(right)) continue;

                res = (res % M + dfs(left) % M * dfs(right) % M) % M;
            }

            return dp[root] = res;
        };

        int res = 0;
        for(int e : arr) res = (res + dfs(e)) % M;

        return res;
    }
};