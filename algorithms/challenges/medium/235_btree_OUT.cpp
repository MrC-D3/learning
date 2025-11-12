// Time 20m. OUT OF TIME (+20).
// Find the Lowest Common Ancestor (LCA) between 2 nodes of a Binary Tree, where
//  a node can be an ancestor of itself.
// Constraints: number of nodes in [2, 105]; node.val in [-10^9, 10^9]; all
// node.val are unique; p != q; p and q always in the Binary Tree.

#include <vector>
#include <stack>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto tree_it = root;
        while (1)
        {
            if (tree_it->val == p->val || tree_it->val == q->val 
              || (tree_it->val < p->val && tree_it->val > q->val)
              || (tree_it->val > p->val && tree_it->val < q->val))
            {
                return tree_it;
            }
            if (tree_it->val > p->val)
            {
                tree_it = tree_it->left;
            }
            else
            {
                tree_it = tree_it->right;
            }

            // Or simpler:
            // if (p->val > root->val && q->val > root->val) ...tree_it->right
            // else if (p->val < root->val && q->val < root->val) ...
            // else return tree_it;
        }

        return nullptr;
    }
};

// You’re not using the BST property that allows you to prune the search.
class Solution_v0 {
public:
    bool is_ancestor(TreeNode* root, int val, vector<TreeNode*>& ancestors)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->val == val)
        {
            ancestors.push_back(root);
            return true;
        }

        if (is_ancestor(root->left, val, ancestors) || is_ancestor(root->right, val, ancestors))
        {
            ancestors.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int found_one{-1};
        vector<int> descendants{p->val, q->val};

        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }

        vector<TreeNode*> p_ancestors;
        vector<TreeNode*> q_ancestors;
        is_ancestor(root, p->val, p_ancestors);
        is_ancestor(root, q->val, q_ancestors);

        int p_i = p_ancestors.size() - 1;
        int q_i = q_ancestors.size() - 1;
        while (p_i >= 0 && q_i >= 0)
        {
            if (p_ancestors[p_i] != q_ancestors[q_i])
            {
                break;
            }

            --p_i;
            --q_i;
        }

        return p_ancestors[p_i+1];
    }
};