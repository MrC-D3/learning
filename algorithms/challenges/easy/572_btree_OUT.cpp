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

// Alternative: Aho–Corasick.

// Alternative: Merkle tree algorithm.
//  - Create an hash for the subtree as hash(hash(left),root,hash(right));
//  - Create an hash for each node in the main tree;
//  - Look for the hash of the subtree in the computed hashes.
// Example of hash(x) = P1*left_hash ^ P2*x' ^ P3*right_hash, where Ps are large
//  primes and x' = x + offset, so even x=0 contributes to the result.

// O(n+m), equivalent to "find the sub-string" problem.
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

        // Used find() here, but not sure it's implemented with KMP.
        return root_string.find(subRoot_string) != root_string.npos;
    }
};

// Still O(N*M), but no TLE.
class Solution_v1 {
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

// Time Limit Exceeded.
class Solution_v0 {
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