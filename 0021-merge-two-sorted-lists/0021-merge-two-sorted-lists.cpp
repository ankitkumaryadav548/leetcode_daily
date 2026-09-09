// T.C => 0(n+m)
//M1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA = a;
        ListNode* tempB = b;

        ListNode* t = new ListNode(100);  // dummy/extra node
        ListNode* tempC = t;

        while (tempA != NULL && tempB != NULL) {
            if (tempA->val <= tempB->val) {

                tempC->next = tempA;
                tempC = tempA;
                tempA = tempA->next;

            }
            else {

                tempC->next = tempB;
                tempC = tempB;
                tempB = tempB->next;

            }
        }

        if (tempA == NULL) {
            tempC->next = tempB;
        }
        else {
            tempC->next = tempA;
        }

        return t->next;
    }
};

