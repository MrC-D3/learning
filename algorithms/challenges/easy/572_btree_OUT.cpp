// Time: 20m. OUT.
// Return true if subRoot is a subtree of root.
// Constraints: root.size in [1, 2000]; subRoot.size in [1, 1000].

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

// Rabin-Karp's solution: use hash.
//

// Find sub-string solution.
class Solution {
public:
    void preOrderSerialize(TreeNode* root, string& serialized){
        if (!root)
        {
            serialized.append("#,");
            return;
        }
        serialized.append(to_string(root->val)+",");
        preOrderSerialize(root->left, serialized);
        preOrderSerialize(root->right, serialized);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string root_string{","};
        string subRoot_string{","}; // To avoid "2" matches "12".

        preOrderSerialize(root, root_string);
        preOrderSerialize(subRoot, subRoot_string);

        return root_string.find(subRoot_string) != root_string.npos;
    }
};

// Time Limit Exceeded.
class Solution {
public:
    bool traverseSubTree(TreeNode* root, TreeNode* subRoot, TreeNode* subChild){
        if (!root && !subChild)
            return true;
        if (!root || !subChild)
            return false;

        bool local_result = false;
        if (root->val == subChild->val)
        {
            local_result = traverseSubTree(root->left, subRoot, subChild->left);
            local_result &= traverseSubTree(root->right, subRoot, subChild->right);
        }

        if (!local_result)
        {
            local_result = traverseSubTree(root->left, subRoot, subRoot);
            local_result |= traverseSubTree(root->right, subRoot, subRoot);
        }

        return local_result;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverseSubTree(root, subRoot, subRoot);
    }
};