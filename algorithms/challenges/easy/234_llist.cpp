// Time: 20m.
// Return true if the Linked List is palindrome; in O(n) time and O(1) space.
// Constraints: list size in [1, 10^5]; node->val in [0, 9].

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Like v1, but less variables.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find the mid of the list.
        auto it_slow = head;
        auto it_fast = head;
        while (it_fast && it_fast->next)
        {
            it_slow = it_slow->next;
            it_fast = it_fast->next->next;
        }
        if (it_fast)
            it_slow = it_slow->next;

        // Reverse the half list pointed by it_slow.
        ListNode* reversed_head = nullptr;
        while (it_slow)
        {
            auto tmp = reversed_head;
            reversed_head = it_slow;
            it_slow = it_slow->next;
            reversed_head->next = tmp;
        }

        while (reversed_head)
        {
            if (reversed_head->val != head->val)
                return false;
            
            reversed_head = reversed_head->next;
            head = head->next;
        }

        return true;
    }
};

// Like v0 but reverse the 2nd half.
class Solution_v1 {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        // Make slow points to the second half of the list.
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr)
            slow = slow->next;
    
        // Revert the second half, so you can stop on nullptr.
        ListNode* reverse_head{nullptr};
        ListNode* it_slow{slow};
        while (it_slow != nullptr)
        {
            auto tmp = it_slow->next;
            it_slow->next = reverse_head;
            reverse_head = it_slow;
            it_slow = tmp;
        }

        // Now compare.
        auto it_reverse{reverse_head};
        auto it = head;
        while (it_reverse != nullptr)
        {
            if (it_reverse->val != it->val)
                return false;
            it_reverse = it_reverse->next;
            it = it->next;
        }

        return true;
    }
};

class Solution_v0 {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Make slow points to the second half of the list.
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // Revert the first half.
        ListNode* reverse_head{nullptr};
        ListNode* it{head};
        while (it != nullptr && it != slow)
        {
            auto tmp = it->next;

            it->next = reverse_head;
            reverse_head = it;
            it = tmp;
        }
        if (fast != nullptr)
            slow = slow->next;

        // Now compare.
        auto it_reverse{reverse_head};
        auto it_slow{slow};
        while (it_reverse != nullptr && it_slow != nullptr)
        {
            if (it_reverse->val != it_slow->val)
                return false;
            it_reverse = it_reverse->next;
            it_slow = it_slow->next;
        }

        return true;
    }
};