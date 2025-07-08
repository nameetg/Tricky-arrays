#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0, n = groups.size();

        while(i < n && j < nums.size()){
            int m = groups[i].size();

            if(j + m <= nums.size() && equal(groups[i].begin(), groups[i].end(), nums.begin() + j)) j += m, i++;
            else j++;
        }

        return i == n;
    }
};