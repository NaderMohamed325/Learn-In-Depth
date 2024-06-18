class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move pointers one position ahead
            curr = next;
        }

        // prev now points to the new head of the reversed list
        return prev;
    }
};
