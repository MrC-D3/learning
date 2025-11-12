// Time: 20m. OK.
// Find if a Linked List has a cycle: end->next != nullptr.
// Constraints: number of nodes in [0, 10^4]; node.val in [-10^5, 10^5].

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        // Safe because check fast because trying to access fast->next.
        while (fast != nullptr && fast->next != nullptr)
        {
            // Increment by 1.
            slow = slow->next;
            // Increment by 2.
            fast = fast->next->next;

            // If same node, there's a cycle.
            // No need to check they're equal because both nullptr: true only
            //  when list.size==1, but you wouldn't enter the loop.
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

class Solution_v0 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) // Always ask if input can be empty!
        {
            return false;
        }
        
        for (int i = 0; i < 10000; i++)
        {
            if (head->next == nullptr)
            {
                return false;
            }
            head = head->next;
        }

        return true;
    }
};