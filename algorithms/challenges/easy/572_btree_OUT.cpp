// Time: 20m. OUT.
// Return true if subRoot is a subtree of root.
// Constraints: root.size in [1, 2000]; subRoot.size in [1, 1000].
// Note: for the easy solution, the O(M*N) is fine; the O(M+N) can be considered
//  a medium solution.

#include <string>

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

// O(N*M), but no TLE. Anyway, naming is bad and it isn't completly the 
//  canonical solution.
class Solution_v0 {
public:
    bool isSubsubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val == subRoot->val && isSubsubtree(root->left, subRoot->left) && 
          isSubsubtree(root->right, subRoot->right))
            return true;
        return false;
    }
    // Test case: [3,4,5,1,null,2] & [3,1,2].
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val == subRoot->val && isSubsubtree(root->left, subRoot->left) && 
          isSubsubtree(root->right, subRoot->right))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
