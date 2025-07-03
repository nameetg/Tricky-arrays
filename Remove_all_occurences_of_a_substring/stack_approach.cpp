#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = part.length();

        for(char c: s){
            st.push(c);
            if(st.size() >= n){
                stack<char> temp = st;
                int idx = n - 1;
                bool isMatch = true;

                while(idx >= 0){
                    if(temp.top() == part[idx]){
                        temp.pop();
                        idx--;
                    }else{
                        isMatch = false;
                        break;
                    }
                }

                if(isMatch){
                    for(int i = 0; i < n; i++) st.pop();
                }
            }
        }

        string res = "";
        while(st.size()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};