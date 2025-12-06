// Time: 20m. OUT.
// Return true if a binary tree is symmetric.
// Constraints: number of nodes in [1, 1000].

#include <deque>
#include <queue>

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

class Solution { // Recursive solution.
public:
    bool compareTrees(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return compareTrees(left->left, right->right) 
          && compareTrees(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return compareTrees(root->left, root->right);
    }
};

class Solution_v1 { // Most compact iterative solution.
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodes; // No need to use deque.
        nodes.push(root->left);
        nodes.push(root->right);

        while (!nodes.empty())
        {
            // Instead of a palindrome check, put nodes that must be equal close
            //  to each other when pushing them, as at init.
            auto nodeL = nodes.front();
            nodes.pop();
            auto nodeR = nodes.front();
            nodes.pop();
            if (nodeL == nullptr && nodeR == nullptr)
                continue;
            if (nodeL == nullptr || nodeR == nullptr)
                return false;
            if (nodeL->val != nodeR->val)
                return false;

            // Push in order as said before.
            nodes.push(nodeL->left);
            nodes.push(nodeR->right);
            nodes.push(nodeL->right);
            nodes.push(nodeR->left);
        }

        return true;
    }
};

class Solution_v0 {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty())
        {
            auto width = nodes.size();
            for (int i = 0; i < width/2; i++)
            {
                if (nodes[i] == nullptr && nodes[width-1-i] == nullptr)
                    continue;
                if (nodes[i] == nullptr || nodes[width-1-i] == nullptr)
                    return false;               
                if (nodes[i]->val != nodes[width-1-i]->val)
                    return false;
            }
            for (int i = 0; i < width; i++)
            {
                auto node = nodes.front();
                nodes.pop_front();
                if (node == nullptr)
                    continue;
                nodes.push_back( node->left );
                nodes.push_back( node->right );
            }
        }

        return true;
    }
};