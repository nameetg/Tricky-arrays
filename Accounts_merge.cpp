#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;
    
    int getP(int node){
        if(node == parent[node]) return node;
        return parent[node] = getP(parent[node]);
    }

    void merge(int u, int v){
        int pu = getP(u), pv = getP(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        map<string, int> m;

        for(int i = 0; i <= n; i++) parent[i] = i;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(m.count(accounts[i][j])) merge(i, m[accounts[i][j]]);
                else m[accounts[i][j]] = i;
            }
        }

        map<int, set<string>> emailGroup;

        for(auto &[email, idx] : m){
            int p = getP(idx);
            emailGroup[p].insert(email);
        }

        vector<vector<string>> res;

        for(auto &[idx, emails] : emailGroup){
            res.push_back({accounts[idx][0]});
            for(const string &email : emails) res.back().push_back(email);
        }

        return res;
    }
};