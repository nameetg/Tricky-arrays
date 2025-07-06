#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> g(n);
        vector<int> vis(n,false);
        int components = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while(q.size()){
                    int node = q.front();
                    q.pop();

                    for(int nei : g[node]){
                        if(!vis[nei]){
                            q.push(nei);
                            vis[nei] = true;
                        }
                    }
                }
            }
        }

        return n - components;
    }
};