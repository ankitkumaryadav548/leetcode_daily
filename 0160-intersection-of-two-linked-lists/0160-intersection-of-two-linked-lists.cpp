
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int n1 = 0;
        while(tempA != NULL){
            n1++;
            tempA = tempA->next;
        }
        int n2 = 0;
        while(tempB != NULL){
            n2++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;

        if(n1 > n2){
            int diff = n1-n2;
            for(int i = 1; i<=diff ; i++){
                tempA = tempA->next ;
            }
            while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;
        }
        else{  //(n1 < n2)
            int diff = n2-n1;
            for(int i = 1; i<=diff ; i++){
                tempB = tempB->next ;
            }
            while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;
        }
        
    }
};