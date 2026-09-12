
class Solution {
public:

    ListNode* sortList(ListNode* head) {

        // If list has 0 or 1 node, it is already sorted
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide the list into two halves
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* first = sortList(head);
        second = sortList(second);

        // Merge the two sorted halves
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (first != NULL && second != NULL) {

            if (first->val <= second->val) {
                current->next = first;
                first = first->next;
            }
            else {
                current->next = second;
                second = second->next;
            }

            current = current->next;
        }

        // Attach remaining nodes
        if (first != NULL) {
            current->next = first;
        }
        else {
            current->next = second;
        }

        return dummy->next;
    }
};
