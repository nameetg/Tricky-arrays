#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string add(string s, int a){
        for(int i = 0; i < s.length(); i++){
            if(i&1){
                int num = ((s[i] - '0') + a) % 10;
                s[i] = num + '0';
            }
        }
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        b = b % n;
        set<string> st;
        queue<string> q;

        st.insert(s);
        q.push(s);

        string res = s;

        while(q.size()){
            string curr = q.front();
            q.pop();

            res = min(res, curr);

            string temp = curr.substr(n - b) + curr.substr(0, n - b);
            if(!st.count(temp)){
                st.insert(temp);
                q.push(temp);
            }

            temp = add(curr, a);
            if(!st.count(temp)){
                st.insert(temp);
                q.push(temp);
            }
        }
        return res;
    }
};