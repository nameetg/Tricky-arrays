#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        
        for(char c: s){
            res += c;
            if(res.length() >= part.length() && res.substr(res.size()-part.size()) == part) {
                res.erase(res.end() - part.size(), res.end());
            }
        }

        return res;
    }
};