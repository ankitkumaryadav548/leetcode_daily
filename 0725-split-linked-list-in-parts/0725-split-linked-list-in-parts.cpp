class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        // Find the length of original linked list
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            temp = temp->next;
            n++;
        }

        // Breaking the list into k parts
        vector<ListNode*> ans;
        int size = n / k;
        int rem = n % k;

        temp = head;

        while (temp != NULL) {

            ListNode* c = new ListNode(100);
            ListNode* tempC = c;

            int s = size;

            if (rem > 0)
                s++;
            rem--;
            for (int i = 1; i <= s; i++) {

                tempC->next = temp;
                temp = temp->next;
                tempC = tempC->next;
            }
            // Important: break the current part
            tempC->next = NULL;
            ans.push_back(c->next);
        }

        // If k is greater than number of nodes,
        // remaining parts will be NULL
        if (ans.size() < k) {
            int extra = k - ans.size();
            for (int i = 1; i <= extra; i++) {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};