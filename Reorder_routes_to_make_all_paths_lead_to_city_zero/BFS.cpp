#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g(n);
        vector<bool> vis(n, false);
        queue<int> q;
        int res = 0;

        for(auto &e : connections){
            g[e[0]].push_back({e[1], true});
            g[e[1]].push_back({e[0], false});
        }

        q.push(0);
        vis[0] = true;

        while(q.size()){
            int node = q.front();
            q.pop();

            for(auto &[nei, isForward] : g[node]){
                if(!vis[nei]){
                    res += isForward;
                    q.push(nei);
                    vis[nei] = true;
                }
            }
        }

        return res;
    }
};