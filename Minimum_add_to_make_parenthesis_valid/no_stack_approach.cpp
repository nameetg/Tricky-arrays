#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, res = 0;

        for(char c: s){
            if(c == '(') open++;
            else{
                if(!open) res++;
                else open--;
            }
        }
        
        return res + open;
    }
};