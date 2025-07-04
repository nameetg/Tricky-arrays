#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool s1Breaks = true, s2Breaks = true;

        for(int i = 0; i < s1.length(); i++){
            if(s1[i] < s2[i]) s1Breaks = false;
            if(s2[i] < s1[i]) s2Breaks = false;
        }

        return s1Breaks || s2Breaks;
    }
};