#include <algorithm>
#include <array>
#include <cctype> // For isalnum() and tolower().
#include <climits> // For constants like INT_MAX.
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int main()
{
    Solution s;

    return 0;
}