// Time: 15m. Ok.
// Return the depth of a Binary Tree.
// Constraints: number of nodes in [0, 10^4]; node values in [-100, 100].

#include <algorithm>
#include <deque>

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

// Iterative solution.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        
        int depth = 0;
        while(!nodes.empty())
        {
            auto level_width = nodes.size();
            depth += 1;

            for (int i = 0; i < level_width; i++)
            {
                auto node = nodes.front();
                nodes.pop_front();
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
            }
        }

        return depth;
    }
};

class Solution_v0 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};