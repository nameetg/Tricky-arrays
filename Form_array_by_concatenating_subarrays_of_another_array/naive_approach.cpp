#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0, n = groups.size();

        while(i < n && j < nums.size()){
            vector<int> &a = groups[i];
            bool flag = true;
            int k = j;
            for(int e : a){
                if(e == nums[k]) k++;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) i++, j = k;
            else j++;
        }

        return i == n;
    }
};