// Time: 20m. Ok.
// Find the middle element of a Linked List. If 2 middle elemennts, return the
//  2nd.

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Even if - to me - the dummy node makes the solution clearer, it isn't needed.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* step_1 = head;
        ListNode* step_2 = head;

        while (step_2 != nullptr && step_2->next != nullptr)
        {
            step_2 = step_2->next->next;
            step_1 = step_1->next;
        }

        return step_1;
    }
};

class Solution_v0 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode node0(0, head);
        ListNode* step_1 = &node0;
        ListNode* step_2 = &node0;

        while (step_2 != nullptr)
        {
            step_2 = step_2->next;
            if (step_2 != nullptr)
                step_2 = step_2 ->next;

            step_1 = step_1->next;
        }

        return step_1;
    }
};