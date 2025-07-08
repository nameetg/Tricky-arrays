#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int open = 0, res = 0, count = 0;

        for(char c: s){
            if(c == '('){
                if(count == 1){
                    if(open > 0) res++, open--;
                    else res+=2;
                    count = 0;
                }
                open++;
            }else{
                count++;
                if(count == 2){
                    if(open > 0) open--;
                    else res++;
                    count = 0;
                }
            }
        }

        if(open > 0) return res + 2 * open - count ;

        return res + 2 * count;
    }
};