// Time: 20m. Ok.

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

// Iterative solution: not better, except for stack space.
// No need to do level check, the important check is node-wise.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*> nodes_p, nodes_q; // Or just one deque<pair<*,*>>.
        nodes_p.push_back(p);
        nodes_q.push_back(q);
        while (!nodes_p.empty() && !nodes_q.empty())
        {
            auto node_p = nodes_p.front();
            nodes_p.pop_front();
            auto node_q = nodes_q.front();
            nodes_q.pop_front();
            if (node_p == nullptr && node_q == nullptr)
                continue;
            if (node_p == nullptr || node_q == nullptr)
                return false;
            if (node_p->val != node_q->val)
                return false;
            nodes_p.push_back(node_p->left);
            nodes_p.push_back(node_p->right);
            nodes_q.push_back(node_q->left);
            nodes_q.push_back(node_q->right);
        }

        return true;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) && (q == nullptr))
            return true;
        if ((p == nullptr) != (q == nullptr))
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};