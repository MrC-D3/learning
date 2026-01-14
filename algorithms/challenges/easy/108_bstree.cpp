// Time: 20m.
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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getMid(nums, 0, nums.size());
    }

private:
    TreeNode* getMid(vector<int>& nums, int start, int end)
    {
        if (start >= end)
            return nullptr;

        int mid = start + (end-start)/2; // Consider >>1 instead of /2.
        auto root = new TreeNode(nums[mid]);
        root->left = getMid(nums, start, mid);
        root->right = getMid(nums, mid+1, end);
        return root;
    }
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
            if (start >= end) // Check it before pushing to avoid pushing.
                continue;
            auto mid = start + ((start-end) >> 1);
            *root = new TreeNode(nums[mid]);
            subtrees.push( {start, mid, &((*root)->left)} );
            subtrees.push( {mid+1, end, &((*root)->right)} );
        }

        return very_root;
    }
};