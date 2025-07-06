#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> g(n);
        vector<bool> vis(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        function<void(int)> dfs = [&](int node) {
            vis[node] = true;

            for(int nei : g[node]){
                if(!vis[nei]) dfs(nei);
            }
        };

        int components = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                dfs(i);
            }
        }

        return n - components;
    }
};