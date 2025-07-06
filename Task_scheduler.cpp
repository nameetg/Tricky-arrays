#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        map<char, int> nextValid;

        for(char c : tasks) freq[c]++;

        int time = 0, remaining = tasks.size();

        while(remaining){
            char bestTask = '*';
            int maxFreq = 0;

            for(auto &[task, f] : freq){
                if(f > 0 && time >= nextValid[task]){
                    if(f > maxFreq) maxFreq = f, bestTask = task;
                }
            }

            if(bestTask != '*'){
                freq[bestTask]--;
                nextValid[bestTask] = time + n + 1;
                remaining--;
            }

            time++;
        }
        
        return time;
    }
};