class Solution {
public:

    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Farzi node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* l = dummy;

        for (int i = 1; i < left; i++) {
            l = l->next;
        }

        ListNode* m = l->next;

        ListNode* r = m;

        for (int i = left; i < right; i++) {
            r = r->next;
        }

        ListNode* third = r->next;


        // Break Part 2 from Part 3
        r->next = NULL;


        ListNode* reversed = reverseList(m);

        l->next = reversed;

        m->next = third;
        return dummy->next;
    }
};