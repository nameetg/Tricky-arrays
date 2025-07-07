#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        q.push({0, 0, 0});
        dis[0][0] = 0;

        while(q.size()){
            int effort = q.top()[0];
            int x = q.top()[1], y = q.top()[2];
            q.pop();

            if(x == n - 1 && y == m - 1) return effort;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int nextEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if(nextEffort < dis[nx][ny]){
                        dis[nx][ny] = nextEffort;
                        q.push({nextEffort, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};