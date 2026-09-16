class Solution {
public:
    void reorderList(ListNode* head) {

        // Step 1: Find middle of linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* a = head;
        ListNode* b = reverseList(slow->next);

        // Break linked list into two parts
        slow->next = NULL;

        // Step 3: Merge two lists alternatively
        ListNode* c = new ListNode(100);   // farzi node
        ListNode* tempC = c;

        ListNode* tempA = a;
        ListNode* tempB = b;

        while (tempA != NULL && tempB != NULL) {

            // Take node from first half
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            // Take node from second half
            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }

        // Attach remaining nodes
        if (tempA != NULL) {
            tempC->next = tempA;
        }

        if (tempB != NULL) {
            tempC->next = tempB;
        }

        head = c->next;
    }


    // Function to reverse linked list
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
};