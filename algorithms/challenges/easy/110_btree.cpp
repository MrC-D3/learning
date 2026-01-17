// Time 15m.
// Return true if a Binary Tree is Height-Balanced: the depth of 2 sub-trees 
//  never differ more than 1.
// Constraints: number of nodes in [0, 5000].

#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.*/
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
    bool isBalanced(TreeNode* root) {
        return (getHeightIfBalanced(root) != -1);
    }

private:
    int getHeightIfBalanced(TreeNode* root)
    {
        if (!root)
            return 0;
        
        auto left_height = getHeightIfBalanced(root->left);
        auto right_height = getHeightIfBalanced(root->right);
        if (left_height == -1 || right_height == -1)
            return -1;
        if (abs(left_height - right_height) > 1)
            return -1;

        return max(left_height, right_height) + 1;
    }
};
