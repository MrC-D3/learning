// Time 15m. OUT.
// Say if a Binary Tree is Height-Balanced: the depth of the 2 sub-trees never 
// differ more than 1.
// Constraints: number of nodes in [0, 5000]; node values in [-10^4, 10^4].

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
    int get_height(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto left_h = get_height(root->left);
        auto right_h = get_height(root->right);
        // If depths are checked only at the end you'll miss case like
        //  [1,2,2,3,null,null,3,4,null,null,4].
        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1)
        {
            return -1;
        }

        return max(left_h, right_h) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return get_height(root) == -1 ? false : true;
    }
};