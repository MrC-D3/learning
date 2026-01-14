// Time: 20m.
// Return a merged non-decreasing-sorted list from 2 non-decreasing lists.
// Constraints: list.size in [0,50]; node.val in [-100, 100]

#include <iostream>

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Common solution.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* it = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                it->next = list1;
                list1 = list1->next;
            }
            else
            {
                it->next = list2;
                list2 = list2->next;             
            }

            it = it->next;
        }
        // This 2 ifs can become a single ?: instruction.
        if (list1)
        {
            it->next = list1;
        }
        if (list2)
        {
            it->next = list2;
        }

        return dummy.next;
    }
};

// Don't find the head, but still complicated.
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

// Try to find which list is the head.
class Solution_v0 {
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