#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(int x, int y, vector<vector<int>> &heights, vector<vector<int>> &vis, int k) {
        int n = heights.size(), m = heights[0].size();
        vis[x][y] = 1;

        if(x == n - 1 && y == m - 1) return true;

        bool res = false;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && abs(heights[nx][ny] - heights[x][y]) <= k){
                res = res | canReach(nx, ny, heights, vis, k);
            }
        }

        return res;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int s = 0, e = 1e9;
        int n = heights.size(), m = heights[0].size();

        while(s <= e){
            int mid = (s + e)/2;
            vector<vector<int>> vis(n, vector<int>(m, 0));

            if(canReach(0, 0, heights, vis, mid)) e = mid - 1;
            else s = mid + 1;
        }

        return s;
    }
};