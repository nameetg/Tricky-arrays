#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;

        function<int(int)> findP = [&] (int node) -> int {
            if(!parent.count(node)) parent[node] = node;
            if(parent[node] != node) parent[node] = findP(parent[node]);
            return parent[node];
        };

        auto merge = [&] (int u, int v){
            parent[findP(u)] = findP(v);
        };

        set<int> uniquePoints;

        for(auto &stone : stones){
            int row = stone[0] ,col = stone[1] + 10001;
            merge(row, col);
        }

        for(auto &stone : stones) uniquePoints.insert(findP(stone[0]));

        return stones.size() - uniquePoints.size();
    }
};