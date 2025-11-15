// Time: 30m. OK.
// Return the Diameter of a Binary Tree, i.e. the max distance between 2 nodes,
//  where the distance is the number of edges.
// Constraints: number of nodes [1, 10^4], node values in [-100, 100].
// Note: despite the node values, null nodes are possible, so the tree can be 
//  skewed.

#include <algorithm>

using namespace std;

/* Definition for a binary tree node. */
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
    int compute_depth(TreeNode* root, int& diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto depth_left = compute_depth(root->left, diameter);
        auto depth_right = compute_depth(root->right, diameter);
        auto current_diameter = depth_left + depth_right;
        diameter = max(diameter, current_diameter);

        return max(depth_left, depth_right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // WRT to the root, left_subtree_depth + right_subtree_depth.
        int result = 0;
        
        compute_depth(root, result);
        return result;
    }
};