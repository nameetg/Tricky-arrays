#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kmpSearch(vector<int> &text, vector<int> &pattern, int start){
        int n = text.size(), m = pattern.size(), len = 0;
        vector<int> lps(m, 0);

        for(int i = 1; i < m;){
            if(pattern[i] == pattern[len]) lps[i++] = ++len;
            else{
                if(len) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }

        int i = start, j = 0;

        while(i < n){
            if(text[i] == pattern[j]){
                i++, j++;
                if(j == m) return i - m;
            }else{
                if(j) j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start = 0;

        for(auto &group : groups){
            int pos = kmpSearch(nums, group, start);

            if(pos == -1) return false;
            start = pos + group.size();
        }
        
        return true;
    }
};