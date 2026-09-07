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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //M1
    //     ListNode* temp = head;
    //     int a = 0;
    //     while(temp != NULL){
    //         a++ ;
    //         temp = temp->next;
    //     }
    //    if(n == a){
    //     head = head->next;
    //     return head;
    //    }
    //    int m = (a-n+1);
    //     int idx = m-1;
    //     temp = head;
    //    for(int i=1;i<=idx-1;i++){
    //     temp = temp -> next;
    //    }
    //    temp->next = temp->next->next;
    //    return head;
    
    //M2 => slow and fast pointer
    //in one pass 
    ListNode* slow = head;
    ListNode* fast = head;

    for(int i=1;i<=n+1;i++){
        if(fast == NULL) return head->next;
        fast = fast->next;
    }
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
    }
    
};