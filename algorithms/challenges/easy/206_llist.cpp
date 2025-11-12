// Time: 20m. Ok.
// Reverse a Linked List.
// Constraints: number of nodes in [0, 5000].
// Try the recursive solution too, even if more space cost because of the stack.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reversed = nullptr;

        while (head != nullptr)
        {
            auto tmp = head;
            head = head->next;
            tmp->next = reversed;
            reversed = tmp;
        }

        return reversed;
    }
};