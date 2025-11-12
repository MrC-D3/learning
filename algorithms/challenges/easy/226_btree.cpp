// Time 15m. OK.
// Given the root of a binary tree, invert the tree, and return its root.
// Example: Input = [2,1,3]; Output = [2,3,1].
// The number of nodes in the tree is in the range [0, 100].

#include <algorithm>

using namespace std;

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }

        // Pre-order swap, but possible also a post-order.
        swap(root->left, root->right);

        // If recursion depth H is too big, consider the iterative approach.
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};