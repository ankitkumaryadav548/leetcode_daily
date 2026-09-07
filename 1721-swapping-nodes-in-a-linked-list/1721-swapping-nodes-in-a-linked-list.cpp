/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // 1. Find the kth node from the beginning
        ListNode* first = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // 2. Find the kth node from the end
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast k positions ahead
        for (int i = 1; i <= k; i++) {
            fast = fast->next;
        }

        // Move both pointers together
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // 3. Swap the values
        int temp = first->val;
        first->val = slow->val;
        slow->val = temp;

        return head;
    }
};