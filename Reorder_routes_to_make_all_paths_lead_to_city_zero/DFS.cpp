#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g(n);

        for(auto &e: connections){
            g[e[0]].push_back({e[1], true});
            g[e[1]].push_back({e[0], false});
        }

        int res = 0;

        function<void(int, int)> dfs = [&] (int node, int parent) {
            for(auto &[nei, isForward] : g[node]){
                if(nei != parent){
                    res += isForward;
                    dfs(nei, node);
                }
            }
        };

        dfs(0, -1);
        return res;
    }
};