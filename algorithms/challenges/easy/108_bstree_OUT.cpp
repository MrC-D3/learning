// Time: 20m. OUT.
// Convert an ascending-ordered array in a height-balanced binary tree.
// Constraints: nodes number in [1, 10^4].

#include <vector>
#include <queue>
#include <tuple>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_iterative {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        queue<tuple<int,int,TreeNode**>> subtrees;
        TreeNode* very_root;
        subtrees.push( {0, nums.size(), &very_root} ); // Consider emplace()!.
        while (!subtrees.empty())
        {
            auto [start, end, root] = subtrees.front();
            subtrees.pop();
            if (start >= end)
                continue;
            auto mid = start + ((start-end) >> 1);
            *root = new TreeNode(nums[mid]);
            subtrees.push( {start, mid, &((*root)->left)} );
            subtrees.push( {mid+1, end, &((*root)->right)} );
        }

        return very_root;
    }
};

class Solution_recursive {
public:
    // End is - as always - the first not-valid position.
    TreeNode* buildBST(vector<int>& nums, int start, int end)
    {
        if (start >= end)
            return nullptr;
        
        // Root at: start + offset.
        int i_root = start + (end-start) / 2; // Consider >>1 instead of /2.
        auto value_root = nums[i_root];
        TreeNode* root = new TreeNode(value_root);
        root->left = buildBST(nums, start, i_root);
        root->right = buildBST(nums, i_root + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size());
    }
};

int main(){}