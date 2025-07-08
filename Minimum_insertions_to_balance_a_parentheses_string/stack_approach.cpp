#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int res = 0, count = 0;
        for(char c : s){
            if(c == '('){
                if(count == 1){
                    if(st.size()){
                        res++;
                        st.pop();
                    }
                    else res += 2;
                }
                st.push(c);
                count = 0;
            }
            else{
                count++;
                if(count == 2){
                    if(st.size()) st.pop();
                    else res++;
                    count = 0;
                }
            }
        }

        if(st.size()) return res + 2 * st.size() - count;

        return res + 2 * count;
    }
};