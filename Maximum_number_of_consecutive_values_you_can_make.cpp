#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());

        int canMake = 0;
        for(int e : coins){
            if(e <= canMake + 1) canMake += e;
            else break;
        }

        return canMake + 1;
    }
};