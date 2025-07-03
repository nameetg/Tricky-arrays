#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        function<TreeNode*(int, int)> solve = [&] (int s, int e) -> TreeNode* {
            if(s > e) return nullptr;
            int idx = s, maxVal = nums[s];
            for(int i = s + 1; i <= e; i++){
                if(nums[i] > maxVal) idx = i, maxVal = nums[i];
            }
            TreeNode* root = new TreeNode(maxVal);
            root->left = solve(s, idx - 1);
            root->right = solve(idx + 1, e);
            return root;
        };

        return solve(0, nums.size() - 1);
    }
};