// Time: 20m for the easy solution, so consider +5m for the medium solution, 
//  i.e. the O(M+N).
// Return true if subRoot is a subtree of root.
// Constraints: root.size in [1, 2000]; subRoot.size in [1, 1000].

#include <string>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Alternative: create an hash for every subtree and confront the hashes.

// A "find sub-string" solution, so O(n+m) if find() is well designed.
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