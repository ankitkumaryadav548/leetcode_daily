
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       ListNode* odd = new ListNode(1);
       ListNode* even = new ListNode(2);
       ListNode* tempo = odd; 
       ListNode* tempE = even;
       ListNode* temp = head;
       int position = 1;
        while(temp != NULL){
        if(position %2 != 0){ // temp is odd
            tempo->next = temp;
            temp = temp->next;
            tempo = tempo->next;
            position ++ ;
       } else{
            tempE->next = temp;
            temp = temp->next;
            tempE = tempE->next;
            position ++ ;

       }
     }
       tempo->next = even->next;
       tempE->next = NULL;
       return odd->next;
    }
};