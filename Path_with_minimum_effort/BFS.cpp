#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<vector<int>> &heights, int k) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m + 1, 0));
        queue<pair<int,int>> q;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        q.push({0, 0});
        vis[0][0] = 1;

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n - 1 && y == m - 1) return true;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && abs(heights[nx][ny] - heights[x][y]) <= k){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int s = 0, e = 1e9;

        while(s <= e){
            int m = (s + e)/2;

            if(canReach(heights, m)) e = m - 1;
            else s = m + 1;
        }

        return s;
    }
};