class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Step 1: Reverse the linked list
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        // Step 2: Keep maximum and remove smaller nodes
        ListNode* temp = head;
        int maxi = head->val;

        while (temp != NULL && temp->next != NULL) {
            // If next node is smaller than maximum
            if (temp->next->val < maxi) {
                 ListNode* target = temp->next;
                // Skip target node
                temp->next = target->next;
                // DON'T delete target on LeetCode
            }
            else {
                // Keep this node
                temp = temp->next;
                // Update maximum
                maxi = temp->val;
            }
        }

        // Step 3: Reverse the list again
        prev = NULL;
        curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};