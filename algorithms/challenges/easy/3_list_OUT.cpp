// OUT OF TIME.
// Time: 20m. Used: 50m.
// Problem description.
// ...

#include <iostream>

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        // Fake head node to simplify the logic at the beginning. 
        ListNode merged;
        merged.next = list1;
        ListNode* it = &merged;
        ListNode* other = list2;
        while (it->next != nullptr)
        {
            if (it->next->val <= other->val)
            {
                it = it->next;
                continue;
            }

            // Here if other->val < it->next->val.
            //  Append the whole list pointed by other.
            //  Now other points to the current sub-list pointed by it->next.
            ListNode* tmp = it->next;
            it->next = other;
            other = tmp;
            it = it->next;
        }

        // In case it1 reached the end, but still nodes in other.
        it->next = other;

        return merged.next;
    }
};

class Solution_v1 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode* head;
        ListNode* from;
        if (list1->val <= list2->val)
        {
            head = list1;
            from = list2;
        }
        else
        {
            head = list2;
            from = list1;
        }
        
        ListNode* head_it = head;
        while (head_it->next != nullptr && from != nullptr)
        {
            if (from->val < head_it->next->val)
            {
                ListNode* tmp = head_it->next;
                head_it->next = from;
                from = from->next;
                head_it->next->next = tmp;
            }
            else
            {
                head_it = head_it->next;
            }
        }

        // Case: 
        if (from != nullptr)
        {
            head_it->next = from;
        }

        return head;
    }
};