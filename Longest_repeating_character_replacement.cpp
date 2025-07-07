#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0, j = 0, count = 0, res = 0;

        while(j < s.length()){
            freq[s[j] - 'A']++;
            count = max(count, freq[s[j] - 'A']);

            while(j - i + 1 - count > k){
                freq[s[i] - 'A']--;
                i++;
            }

            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};